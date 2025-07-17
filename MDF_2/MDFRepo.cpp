//
// Created by giaco on 06/07/2022.
//

#include "MDFRepo.h"
#include <algorithm>
#include "MDFI.h"
#include <iterator>

template<class T>
void MDFRepo<T>::addGraph(Graph<T> *tobeAdded) {
    tobeAdded->compile();
    this->list_of_graphs.push_back(tobeAdded);

}

template<class T>
void MDFRepo<T>::startPool(int nw) {
    this->pool.n_worker = nw;
    this->pool.terminate = false;
    this->pool.n_added = 0;
    this->pool.n_done = 0;
    this->pool.start();

}

template<class T>
void MDFRepo<T>::killPool() {
    this->pool.shutdown();
}

template<class T>
void MDFRepo<T>::startEmitter(int numberOfTasks, bool threadedEmitter) {
    this->global_id = 0;
    for (int i = 0; i < this->list_of_graphs.size(); ++i) {
        this->global_id += this->list_of_graphs[i]->list_of_nodes.size();
    }
    if (!threadedEmitter) {
        for (int i = 0; i < numberOfTasks; ++i) {
            //  std::cout<<"GRAPH SIZE: "<<this->list_of_graphs.size()<<std::endl;
            for (int j = 0; j < this->list_of_graphs.size(); ++j) {

                for (int k = 0; k < this->list_of_graphs[j]->list_of_nodes.size(); ++k) {
                    if (k == 0) {
                        //    std::cout << "Inserted in firable ID[" << this->global_id << "]" << std::endl;
                        MDFI first = this->list_of_graphs[j]->list_of_nodes[k]->generateMDFI(this->global_id * i,
                                                                                             &this->waiting,
                                                                                             &this->mutex,
                                                                                             &this->promotable);
                        first.firable = true;
                        first.inputList[0].presence_bit = true;
                        first.inputList[0].value = 10.0;
                        this->firable.add_element(first);
                    } else {
                        //std::cout << "Inserted in waiting ID[" << this->global_id << "]" << std::endl;

                        this->insertInWaiting(
                                this->list_of_graphs[j]->list_of_nodes[k]->generateMDFI(this->global_id * i,
                                                                                        &this->waiting, &this->mutex,
                                                                                        &this->promotable));//TODO MODIFY TO WORK WITH MORE GRAPHS
                    }
                    //std::cout << "GLOBAL ID: " << this->global_id << std::endl;

                }


            }
        }
        this->streamEnded = true;
    } else {
        this->emitter_async = true;
        this->emitterhtread = (std::thread([this, numberOfTasks] { this->startEmitterThreaded(numberOfTasks); }));
    }

}

template<class T>
void MDFRepo<T>::startEmitterThreaded(int numberOfTasks) {
    for (int i = 0; i < numberOfTasks; ++i) {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        //  std::cout<<"GRAPH SIZE: "<<this->list_of_graphs.size()<<std::endl;
        for (int j = 0; j < this->list_of_graphs.size(); ++j) {
            std::unique_lock lock(this->mutex);
            for (int k = 0; k < this->list_of_graphs[j]->list_of_nodes.size(); ++k) {
                if (k == 0) {
                    //    std::cout << "Inserted in firable ID[" << this->global_id << "]" << std::endl;
                    MDFI first = this->list_of_graphs[j]->list_of_nodes[k]->generateMDFI(this->global_id * i,
                                                                                         &this->waiting, &this->mutex,
                                                                                         &this->promotable);
                    first.firable = true;
                    first.inputList[0].presence_bit = true;
                    first.inputList[0].value = 10.0;
                    this->firable.add_element(first);
                } else {
                    //std::cout << "Inserted in waiting ID[" << this->global_id << "]" << std::endl;

                    this->insertInWaiting(
                            this->list_of_graphs[j]->list_of_nodes[k]->generateMDFI(this->global_id * i, &this->waiting,
                                                                                    &this->mutex,
                                                                                    &this->promotable));//TODO MODIFY TO WORK WITH MORE GRAPHS
                }
                //std::cout << "GLOBAL ID: " << this->global_id << std::endl;

            }

        }
        this->cv.notify_all();
    }
    this->streamEnded = true;
}

template<class T>
void MDFRepo<T>::startFlow(int nw) {
    std::cout << nw << ", ";
    this->startPool(nw);

    //while (!this->firable.empty()|!this->waiting.empty()) {
    while (!this->streamEnded || (!this->firable.is_empty() || !this->waiting.empty())) {

        while (!this->firable.is_empty()) {
            // std::cout << this->firable.size() << std::endl;
            //  std::cout << "CHECK Firable" << std::endl;
            //for (int i = 0; i < this->firable.size(); ++i) {
            //  if (this->firable[i].checkIfFirable()) {

            //    std::cout << "found firable" << std::endl;
            MDFI executable = this->firable.get_element();
            //   std::cout << executable.id << "\t" << executable.inputList[0].value << std::endl;
            this->pool.addTask(std::bind(&MDFRepo::execute, this, executable));
//            this->pool.addTask( this->execute(executable));

            // }
            //  }
            /*  std::cout<<"CHECK Firable"<<std::endl;
              for(auto mdfi: this->waiting){
                  if(mdfi.second.checkIfFirable()){
                      this->insertInWaiting(mdfi.second);


                  }
              }*/
        }
        //   std::cout << "CHECK Upgradable" << std::endl;
        /////////////////////////////////////////////////////////////////////////////
        /* std::vector<unsigned long int> toRemove;
         for (auto mdfi: this->waiting) {
             if (mdfi.second.checkIfFirable()) {
                 //   std::cout << "TO Be PROMOTED" << std::endl;
                 this->promoteToFirable(mdfi.second);
                 //  std::cout << "PROMOTED" << std::endl;


                 //  std::cout << "toDelete" << std::endl;
                 toRemove.push_back(mdfi.first);

                 //  std::cout<<"deleted"<<std::endl;
             }
         }*/
        {
            std::unique_lock<std::shared_mutex> lock(this->mutex);
            while (!this->promotable.is_empty()) {
                auto toDelete = this->waiting.find(this->promotable.get_element());
                if (toDelete != this->waiting.end()) {
                    this->promoteToFirable(toDelete->second);
                    this->waiting.erase(toDelete);
                }
            }
        }
        this->cv.notify_all();

    }
    /*   std::cout << "KILLING " << !this->streamEnded << std::endl;
       std::cout << "KILLING " << !this->firable.is_empty() << std::endl;
       std::cout << "KILLING " << !this->waiting.empty() << std::endl;*/
    if (this->emitter_async)
        this->emitterhtread.join();
    this->killPool();

}

template<class T>
void MDFRepo<T>::insertInWaiting(MDFI<T> toBeInserted) {
    // this->waiting.push_back(toBeInserted);
    // std::cout << "INSERT I WAITING ID[" << toBeInserted.id << "]" << std::endl;
    this->waiting.insert(std::pair<unsigned long int, MDFI<T>>(toBeInserted.id, toBeInserted));
}

template<class T>
void MDFRepo<T>::promoteToFirable(MDFI<T> toPromote) {
    //TODO MAKE LOCKING


    //this->firable.push_back(toPromote);
    this->firable.add_element(toPromote);


}

template<class T>
void MDFRepo<T>::execute(MDFI<T> toCompute) {
    //TODO Pass to pool


    // std::cout << "PREFIRE" << std::endl;
    toCompute.execute();


    /* if (toCompute.isLast){
        //for (int j = 0; j < toCompute.output_array.size(); ++j) {

           // std::cout << "OUTPUT ARRAY POS[" << toCompute.id << "] =" << toCompute.output_array[j] << std::endl;
        //}
    } else*/ {
        // std::cout << "Destination check" << std::endl;
        if (!toCompute.isLast) {
            std::shared_lock<std::shared_mutex> lock(*toCompute.mutexPointer);


            for (int j = 0; j < toCompute.destinationList.size(); ++j) {

                //   std::cout << "Destination check size " << toCompute.destinationList.size() << std::endl;
                //  std::cout << "searching for MDFI with ID: " << toCompute.destinationList[j].destination_MDFI << std::endl;
                while (toCompute.pMap->find(toCompute.destinationList[j].destination_MDFI) == toCompute.pMap->end()) {
                    cv.wait(lock);
                }

                auto result = toCompute.pMap->find(toCompute.destinationList[j].destination_MDFI);
                // std::cout << "MDFI FOUND WITH ID: " << result->first << std::endl;

                // std::cout<<"RES: "<<result->second.id<<std::endl;
                result->second.inputList[toCompute.destinationList[j].position_in_destination_token_list].value = toCompute.output_array[toCompute.destinationList[j].index_of_current_output];
                //std::cout<<"RES: "<<result->first<<std::endl;
                //std::cout<<"YO! "<<result->second.inputList[toCompute.destinationList[j].position_in_destination_token_list].presence_bit<<std::endl;

                result->second.inputList[toCompute.destinationList[j].position_in_destination_token_list].presence_bit = true;
                //std::cout<<"YO 2 "<<result->first<<std::endl;


                if (result->second.checkIfFirable()) {

                    toCompute.toPromote->add_element_front(result->first);

                }
                cv.notify_all();
            }
        }
        else{
            this->resultList.add_element(std::pair<unsigned long int,T>(toCompute.id,toCompute.output_array[0]));
        }

        // std::cout << "Destinations updated" << std::endl;
    }

    //TODO Move output to dest
}

template
class MDFRepo<float>;

template
class MDFRepo<int>;
