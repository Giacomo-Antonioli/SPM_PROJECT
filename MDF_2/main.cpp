//
// Created by giaco on 18/05/2022.
//
#include <stdlib.h>
#include <iostream>

#include <thread>
#include <chrono>
#include "utimer.cpp"
#include "MDFRepo.h"
//#define CYCLE 100000
#include <cmath>
#define GRA 3

int main(int argc, char *argv[]) {
   // std::cout<<"--------------------------------------------------"<<std::endl;
    int CYCLE= stoi(argv[1]);
    int nTasks= stoi(argv[2]);
    int nWorkers= stoi(argv[3]);
    std::cout<<nTasks<<", ";
    std::cout<<CYCLE<<", ";
if(GRA==1) {
    Node<float> A(1, 1, 5);//4
    Node<float> B(2, 1, 2);//2
    Node<float> C(3, 1, 1);
    Node<float> D(4, 1, 1);
    Node<float> E(5, 1, 1);
    Node<float> F(6, 3, 1);
    Node<float> G(7, 1, 1);
    Node<float> H(8, 1, 1);
    Node<float> I(9, 4, 1);


    A.addDep(&B);
    A.addDep(&C);
    A.addDep(&D);
    A.addDep(&E);
    A.addDep(&H);
    B.addDep(&G);
    B.addDep(&I);
    C.addDep(&F);
    D.addDep(&F);
    E.addDep(&F);
    F.addDep(&I);
    G.addDep(&I);
    H.addDep(&I);


    A.addFunction([CYCLE](std::vector<float> values) {
        float ab, ac, ad, ae, ah, x;

        x = values[0];
        ab = x + 1;
        ac = x + 1;
        ad = x + 1;
        ae = x + 1;
        ah = x + 1;
        for (int i = 0; i < CYCLE; i++) {
            ab = sin(sin(sin(ab)));
            ac = cos(cos(sin(ac)));
            ad = sin(tan(sin(ad))) + 3;
            ae = sin(tan(sin(ae)));
            ah = cos(cos(sin(ah))) + 5;
        }


        return (std::vector<float>{ab, ac, ad, ae, ah});
        //std::this_thread::sleep_for(std::chrono::milliseconds(500));
    });
    B.addFunction([CYCLE](std::vector<float> values) {
        float a, bg, bi;

        a = values[0];

        bg = a + 1;
        bi = a + 1;
        for (int i = 0; i < CYCLE; i++) {
            bg = sin(sin(sin(bg)));
            bi = cos(cos(sin(bi)));

        }
        return (std::vector<float>{bg, bi});
        //std::this_thread::sleep_for(std::chrono::milliseconds(500));
    });
    C.addFunction([CYCLE](std::vector<float> values) {
        float a, cf;
        a = values[0];

        cf = a + 1;
        for (int i = 0; i < CYCLE; i++) {

            cf = cos(cos(sin(cf))) + 5;
        }

        return (std::vector<float>{cf});
        //std::this_thread::sleep_for(std::chrono::milliseconds(500));
    });
    D.addFunction([CYCLE](std::vector<float> values) {
        float a, df;

        a = values[0];

        df = a + 1;
        for (int i = 0; i < CYCLE; i++) {
            df = sin(sin(sin(df)));

        }

        return (std::vector<float>{df});
        //std::this_thread::sleep_for(std::chrono::milliseconds(500));
    });
    E.addFunction([CYCLE](std::vector<float> values) {
        float a, ef;

        a = values[0];

        ef = a + 1;

        for (int i = 0; i < CYCLE; i++) {
            ef = cos(cos(sin(ef)));

        }
        return (std::vector<float>{ef});
        //std::this_thread::sleep_for(std::chrono::milliseconds(500));
    });
    F.addFunction([CYCLE](std::vector<float> values) {
        float c, d, e, fi;

        c = values[0];
        d = values[1];
        e = values[2];
        fi = c + d + e + 1;
        for (int i = 0; i < CYCLE; i++) {
            fi = cos(cos(sin(fi)));

        }

        return (std::vector<float>{fi});
        //std::this_thread::sleep_for(std::chrono::milliseconds(500));
    });
    G.addFunction([CYCLE](std::vector<float> values) {
        float b, gi;

        b = values[0];
        gi = b + 1;
        for (int i = 0; i < CYCLE; i++) {
            gi = tan(cos(sin(gi)));

        }

        return (std::vector<float>{gi});
        //std::this_thread::sleep_for(std::chrono::milliseconds(500));
    });
    H.addFunction([CYCLE](std::vector<float> values) {
        float a, hi;

        a = values[0];
        hi = a + 1;
        for (int i = 0; i < CYCLE; i++) {
            hi = sin(exp(sin(hi)));

        }
        return (std::vector<float>{hi});
        //std::this_thread::sleep_for(std::chrono::milliseconds(500));
    });
    I.addFunction([CYCLE](std::vector<float> values) {


        float b, f, g, h, res;
        b = values[0];
        f = values[1];
        g = values[2];
        h = values[0];

        res = b + f + g + h + 1;
        for (int i = 0; i < CYCLE; i++) {
            res = cos(cos(cos(b))) + cos(cos(sin(f))) + cos(tan(sin(g))) + sin(cos(sin(h)));

        }

        return (std::vector<float>{res});
        //std::this_thread::sleep_for(std::chrono::milliseconds(500));
    });

    Graph<float> g;
    g.addNode(&A);
    g.addNode(&B);
    g.addNode(&C);
    g.addNode(&D);
    g.addNode(&E);
    g.addNode(&F);
    g.addNode(&G);
    g.addNode(&H);
    g.addNode(&I);


    MDFRepo<float> Repo;
    Repo.addGraph(&g);
    Repo.startEmitter(nTasks, false);

    START(start);
    Repo.startFlow(nWorkers);
    STOP(start, end);
    std::cout << end << std::endl;
    //  std::cout<<"Elapsed: "<<(float)end/1000000000.0<<" s"<<std::endl;
    //std::cout<<"--------------------------------------------------"<<std::endl;
}
 if (GRA==2){
    Node<float> A(1, 1, 1);//4
    Node<float> B(2, 1, 1);//2
    Node<float> C(3, 1, 1);
    Node<float> D(4, 1, 1);
    Node<float> E(5, 1, 1);
    Node<float> F(6, 1, 1);
    Node<float> G(7, 1, 1);
    Node<float> H(8, 1, 1);
    Node<float> I(9, 1, 1);
    Node<float> L(10, 1, 1);//4
    Node<float> M(11, 1, 1);//2
    Node<float> N(12, 1, 1);
    Node<float> O(13, 1, 1);
    Node<float> P(14, 1, 1);
    Node<float> Q(15, 1, 1);
    Node<float> R(16, 1, 1);
    Node<float> S(17, 1, 1);
    Node<float> T(18, 1, 1);


    A.addDep(&B);
    B.addDep(&C);
    C.addDep(&D);
    D.addDep(&E);
    E.addDep(&F);
    F.addDep(&G);
    G.addDep(&H);
    H.addDep(&I);
    I.addDep(&L);
    L.addDep(&M);
    M.addDep(&N);
    N.addDep(&O);
    O.addDep(&P);
    P.addDep(&Q);
    Q.addDep(&R);
    R.addDep(&S);
    S.addDep(&T);




    A.addFunction([CYCLE](std::vector<float> values) {
        float a, cf;
        a = values[0];

        cf = a + 1;
        for (int i = 0; i < CYCLE; i++) {

            cf = cos(cos(sin(cf))) + 5;
        }

        return (std::vector<float>{cf});
        //std::this_thread::sleep_for(std::chrono::milliseconds(500));
    });
    B.addFunction([CYCLE](std::vector<float> values) {
        float a, cf;
        a = values[0];

        cf = a + 1;
        for (int i = 0; i < CYCLE; i++) {

            cf = cos(cos(sin(cf))) + 5;
        }

        return (std::vector<float>{cf});
        //std::this_thread::sleep_for(std::chrono::milliseconds(500));
    });
    C.addFunction([CYCLE](std::vector<float> values) {
        float a, cf;
        a = values[0];

        cf = a + 1;
        for (int i = 0; i < CYCLE; i++) {

            cf = cos(cos(sin(cf))) + 5;
        }

        return (std::vector<float>{cf});
        //std::this_thread::sleep_for(std::chrono::milliseconds(500));
    });
    D.addFunction([CYCLE](std::vector<float> values) {
        float a, cf;
        a = values[0];

        cf = a + 1;
        for (int i = 0; i < CYCLE; i++) {

            cf = cos(cos(sin(cf))) + 5;
        }

        return (std::vector<float>{cf});
        //std::this_thread::sleep_for(std::chrono::milliseconds(500));
    });
    E.addFunction([CYCLE](std::vector<float> values) {
        float a, cf;
        a = values[0];

        cf = a + 1;
        for (int i = 0; i < CYCLE; i++) {

            cf = cos(cos(sin(cf))) + 5;
        }

        return (std::vector<float>{cf});
        //std::this_thread::sleep_for(std::chrono::milliseconds(500));
    });
    F.addFunction([CYCLE](std::vector<float> values) {
        float a, cf;
        a = values[0];

        cf = a + 1;
        for (int i = 0; i < CYCLE; i++) {

            cf = cos(cos(sin(cf))) + 5;
        }

        return (std::vector<float>{cf});
        //std::this_thread::sleep_for(std::chrono::milliseconds(500));
    });
    G.addFunction([CYCLE](std::vector<float> values) {
        float a, cf;
        a = values[0];

        cf = a + 1;
        for (int i = 0; i < CYCLE; i++) {

            cf = cos(cos(sin(cf))) + 5;
        }

        return (std::vector<float>{cf});
        //std::this_thread::sleep_for(std::chrono::milliseconds(500));
    });
    H.addFunction([CYCLE](std::vector<float> values) {
        float a, cf;
        a = values[0];

        cf = a + 1;
        for (int i = 0; i < CYCLE; i++) {

            cf = cos(cos(sin(cf))) + 5;
        }

        return (std::vector<float>{cf});
        //std::this_thread::sleep_for(std::chrono::milliseconds(500));
    });
    I.addFunction([CYCLE](std::vector<float> values) {
        float a, cf;
        a = values[0];

        cf = a + 1;
        for (int i = 0; i < CYCLE; i++) {

            cf = cos(cos(sin(cf))) + 5;
        }

        return (std::vector<float>{cf});
        //std::this_thread::sleep_for(std::chrono::milliseconds(500));
    });
    L.addFunction([CYCLE](std::vector<float> values) {
        float a, cf;
        a = values[0];

        cf = a + 1;
        for (int i = 0; i < CYCLE; i++) {

            cf = cos(cos(sin(cf))) + 5;
        }

        return (std::vector<float>{cf});
        //std::this_thread::sleep_for(std::chrono::milliseconds(500));
    });
    M.addFunction([CYCLE](std::vector<float> values) {
        float a, cf;
        a = values[0];

        cf = a + 1;
        for (int i = 0; i < CYCLE; i++) {

            cf = cos(cos(sin(cf))) + 5;
        }

        return (std::vector<float>{cf});
        //std::this_thread::sleep_for(std::chrono::milliseconds(500));
    });
    N.addFunction([CYCLE](std::vector<float> values) {
        float a, cf;
        a = values[0];

        cf = a + 1;
        for (int i = 0; i < CYCLE; i++) {

            cf = cos(cos(sin(cf))) + 5;
        }

        return (std::vector<float>{cf});
        //std::this_thread::sleep_for(std::chrono::milliseconds(500));
    });
    O.addFunction([CYCLE](std::vector<float> values) {
        float a, cf;
        a = values[0];

        cf = a + 1;
        for (int i = 0; i < CYCLE; i++) {

            cf = cos(cos(sin(cf))) + 5;
        }

        return (std::vector<float>{cf});
        //std::this_thread::sleep_for(std::chrono::milliseconds(500));
    });
    P.addFunction([CYCLE](std::vector<float> values) {
        float a, cf;
        a = values[0];

        cf = a + 1;
        for (int i = 0; i < CYCLE; i++) {

            cf = cos(cos(sin(cf))) + 5;
        }

        return (std::vector<float>{cf});
        //std::this_thread::sleep_for(std::chrono::milliseconds(500));
    });
    Q.addFunction([CYCLE](std::vector<float> values) {
        float a, cf;
        a = values[0];

        cf = a + 1;
        for (int i = 0; i < CYCLE; i++) {

            cf = cos(cos(sin(cf))) + 5;
        }

        return (std::vector<float>{cf});
        //std::this_thread::sleep_for(std::chrono::milliseconds(500));
    });
    R.addFunction([CYCLE](std::vector<float> values) {
        float a, cf;
        a = values[0];

        cf = a + 1;
        for (int i = 0; i < CYCLE; i++) {

            cf = cos(cos(sin(cf))) + 5;
        }

        return (std::vector<float>{cf});
        //std::this_thread::sleep_for(std::chrono::milliseconds(500));
    });
    S.addFunction([CYCLE](std::vector<float> values) {
        float a, cf;
        a = values[0];

        cf = a + 1;
        for (int i = 0; i < CYCLE; i++) {

            cf = cos(cos(sin(cf))) + 5;
        }

        return (std::vector<float>{cf});
        //std::this_thread::sleep_for(std::chrono::milliseconds(500));
    });
    T.addFunction([CYCLE](std::vector<float> values) {
        float a, cf;
        a = values[0];

        cf = a + 1;
        for (int i = 0; i < CYCLE; i++) {

            cf = cos(cos(sin(cf))) + 5;
        }

        return (std::vector<float>{cf});
        //std::this_thread::sleep_for(std::chrono::milliseconds(500));
    });

    Graph<float> g;
    g.addNode(&A);
    g.addNode(&B);
    g.addNode(&C);
    g.addNode(&D);
    g.addNode(&E);
    g.addNode(&F);
    g.addNode(&G);
    g.addNode(&H);
    g.addNode(&I);
    g.addNode(&L);
    g.addNode(&M);
    g.addNode(&N);
    g.addNode(&O);
    g.addNode(&P);
    g.addNode(&Q);
    g.addNode(&R);
    g.addNode(&S);
    g.addNode(&T);



    MDFRepo<float> Repo;
    Repo.addGraph(&g);
    Repo.startEmitter(nTasks, false);

    START(start);
    Repo.startFlow(nWorkers);
    STOP(start, end);
    std::cout << end << std::endl;

}
 if (GRA==3){
    Node<float> A(1, 1, 16);//4
    Node<float> B(2, 1, 1);//2
    Node<float> C(3, 1, 1);
    Node<float> D(4, 1, 1);
    Node<float> E(5, 1, 1);
    Node<float> F(6, 1, 1);
    Node<float> G(7, 1, 1);
    Node<float> H(8, 1, 1);
    Node<float> I(9, 1, 1);
    Node<float> L(10, 1, 1);//4
    Node<float> M(11, 1, 1);//2
    Node<float> N(12, 1, 1);
    Node<float> O(13, 1, 1);
    Node<float> P(14, 1, 1);
    Node<float> Q(15, 1, 1);
    Node<float> R(16, 1, 1);
    Node<float> S(17, 1, 1);
    Node<float> T(18, 16, 1);


    A.addDep(&B);
    A.addDep(&C);
    A.addDep(&D);
    A.addDep(&E);
    A.addDep(&F);
    A.addDep(&G);
    A.addDep(&H);
    A.addDep(&I);
    A.addDep(&L);
    A.addDep(&M);
    A.addDep(&N);
    A.addDep(&O);
    A.addDep(&P);
    A.addDep(&Q);
    A.addDep(&R);
    A.addDep(&S);

    B.addDep(&T);
    C.addDep(&T);
    D.addDep(&T);
    E.addDep(&T);
    F.addDep(&T);
    G.addDep(&T);
    H.addDep(&T);
    I.addDep(&T);
    L.addDep(&T);
    M.addDep(&T);
    N.addDep(&T);
    O.addDep(&T);
    P.addDep(&T);
    Q.addDep(&T);
    R.addDep(&T);
    S.addDep(&T);







    A.addFunction([CYCLE](std::vector<float> values) {
        float a, b,c,d,e,f,g,h,si,l,m,n,o,p,q,r,s;
        a = values[0];

        b = a + 1;
        c = a + 1;
        d = a + 1;
        e = a + 1;
        f = a + 1;
        g = a + 1;
        h = a + 1;
        si = a + 1;
        l = a + 1;
        m = a + 1;
        n = a + 1;
        o = a + 1;
        p = a + 1;
        q = a + 1;
        r = a + 1;
        s = a + 1;
        for (int i = 0; i < CYCLE; i++) {

            b = cos(cos(sin(b))) + 5;
            c = cos(cos(sin(c))) + 5;
            d = cos(cos(sin(d))) + 5;
            e = cos(cos(sin(e))) + 5;
            f = cos(cos(sin(f))) + 5;
            g = cos(cos(sin(g))) + 5;
            h = cos(cos(sin(h))) + 5;
            si = cos(cos(sin(si))) + 5;
            l = cos(cos(sin(l))) + 5;
            m = cos(cos(sin(m))) + 5;
            n = cos(cos(sin(n))) + 5;
            o = cos(cos(sin(o))) + 5;
            p = cos(cos(sin(p))) + 5;
            q = cos(cos(sin(q))) + 5;
            r = cos(cos(sin(r))) + 5;
            s = cos(cos(sin(s))) + 5;
        }

        return (std::vector<float>{ b,c,d,e,f,g,h,si,l,m,n,o,p,q,r,s});
        //std::this_thread::sleep_for(std::chrono::milliseconds(500));
    });
    B.addFunction([CYCLE](std::vector<float> values) {
        float a, cf;
        a = values[0];

        cf = a + 1;
        for (int i = 0; i < CYCLE; i++) {

            cf = cos(cos(sin(cf))) + 5;
        }

        return (std::vector<float>{cf});
        //std::this_thread::sleep_for(std::chrono::milliseconds(500));
    });
    C.addFunction([CYCLE](std::vector<float> values) {
        float a, cf;
        a = values[0];

        cf = a + 1;
        for (int i = 0; i < CYCLE; i++) {

            cf = cos(cos(sin(cf))) + 5;
        }

        return (std::vector<float>{cf});
        //std::this_thread::sleep_for(std::chrono::milliseconds(500));
    });
    D.addFunction([CYCLE](std::vector<float> values) {
        float a, cf;
        a = values[0];

        cf = a + 1;
        for (int i = 0; i < CYCLE; i++) {

            cf = cos(cos(sin(cf))) + 5;
        }

        return (std::vector<float>{cf});
        //std::this_thread::sleep_for(std::chrono::milliseconds(500));
    });
    E.addFunction([CYCLE](std::vector<float> values) {
        float a, cf;
        a = values[0];

        cf = a + 1;
        for (int i = 0; i < CYCLE; i++) {

            cf = cos(cos(sin(cf))) + 5;
        }

        return (std::vector<float>{cf});
        //std::this_thread::sleep_for(std::chrono::milliseconds(500));
    });
    F.addFunction([CYCLE](std::vector<float> values) {
        float a, cf;
        a = values[0];

        cf = a + 1;
        for (int i = 0; i < CYCLE; i++) {

            cf = cos(cos(sin(cf))) + 5;
        }

        return (std::vector<float>{cf});
        //std::this_thread::sleep_for(std::chrono::milliseconds(500));
    });
    G.addFunction([CYCLE](std::vector<float> values) {
        float a, cf;
        a = values[0];

        cf = a + 1;
        for (int i = 0; i < CYCLE; i++) {

            cf = cos(cos(sin(cf))) + 5;
        }

        return (std::vector<float>{cf});
        //std::this_thread::sleep_for(std::chrono::milliseconds(500));
    });
    H.addFunction([CYCLE](std::vector<float> values) {
        float a, cf;
        a = values[0];

        cf = a + 1;
        for (int i = 0; i < CYCLE; i++) {

            cf = cos(cos(sin(cf))) + 5;
        }

        return (std::vector<float>{cf});
        //std::this_thread::sleep_for(std::chrono::milliseconds(500));
    });
    I.addFunction([CYCLE](std::vector<float> values) {
        float a, cf;
        a = values[0];

        cf = a + 1;
        for (int i = 0; i < CYCLE; i++) {

            cf = cos(cos(sin(cf))) + 5;
        }

        return (std::vector<float>{cf});
        //std::this_thread::sleep_for(std::chrono::milliseconds(500));
    });
    L.addFunction([CYCLE](std::vector<float> values) {
        float a, cf;
        a = values[0];

        cf = a + 1;
        for (int i = 0; i < CYCLE; i++) {

            cf = cos(cos(sin(cf))) + 5;
        }

        return (std::vector<float>{cf});
        //std::this_thread::sleep_for(std::chrono::milliseconds(500));
    });
    M.addFunction([CYCLE](std::vector<float> values) {
        float a, cf;
        a = values[0];

        cf = a + 1;
        for (int i = 0; i < CYCLE; i++) {

            cf = cos(cos(sin(cf))) + 5;
        }

        return (std::vector<float>{cf});
        //std::this_thread::sleep_for(std::chrono::milliseconds(500));
    });
    N.addFunction([CYCLE](std::vector<float> values) {
        float a, cf;
        a = values[0];

        cf = a + 1;
        for (int i = 0; i < CYCLE; i++) {

            cf = cos(cos(sin(cf))) + 5;
        }

        return (std::vector<float>{cf});
        //std::this_thread::sleep_for(std::chrono::milliseconds(500));
    });
    O.addFunction([CYCLE](std::vector<float> values) {
        float a, cf;
        a = values[0];

        cf = a + 1;
        for (int i = 0; i < CYCLE; i++) {

            cf = cos(cos(sin(cf))) + 5;
        }

        return (std::vector<float>{cf});
        //std::this_thread::sleep_for(std::chrono::milliseconds(500));
    });
    P.addFunction([CYCLE](std::vector<float> values) {
        float a, cf;
        a = values[0];

        cf = a + 1;
        for (int i = 0; i < CYCLE; i++) {

            cf = cos(cos(sin(cf))) + 5;
        }

        return (std::vector<float>{cf});
        //std::this_thread::sleep_for(std::chrono::milliseconds(500));
    });
    Q.addFunction([CYCLE](std::vector<float> values) {
        float a, cf;
        a = values[0];

        cf = a + 1;
        for (int i = 0; i < CYCLE; i++) {

            cf = cos(cos(sin(cf))) + 5;
        }

        return (std::vector<float>{cf});
        //std::this_thread::sleep_for(std::chrono::milliseconds(500));
    });
    R.addFunction([CYCLE](std::vector<float> values) {
        float a, cf;
        a = values[0];

        cf = a + 1;
        for (int i = 0; i < CYCLE; i++) {

            cf = cos(cos(sin(cf))) + 5;
        }

        return (std::vector<float>{cf});
        //std::this_thread::sleep_for(std::chrono::milliseconds(500));
    });
    S.addFunction([CYCLE](std::vector<float> values) {
        float a, cf;
        a = values[0];

        cf = a + 1;
        for (int i = 0; i < CYCLE; i++) {

            cf = cos(cos(sin(cf))) + 5;
        }

        return (std::vector<float>{cf});
        //std::this_thread::sleep_for(std::chrono::milliseconds(500));
    });
    T.addFunction([CYCLE](std::vector<float> values) {
        float res,b,c,d,e,f,g,h,i,l,m,n,o,p,q,r,s;
        b = values[0];
        c = values[1];
        d = values[2];
        e = values[3];
        f = values[4];
        g = values[5];
        h = values[6];
        i = values[7];
        l = values[8];
        m = values[9];
        n = values[10];
        o = values[11];
        p = values[12];
        q = values[13];
        r = values[14];
        s = values[15];
res=b+c+d+e+f+g+h+i+l+m+n+o+p+q+r+s;
        for (int i = 0; i < CYCLE; i++) {

            res = cos(cos(sin(res))) + 5;
        }

        return (std::vector<float>{res});
        //std::this_thread::sleep_for(std::chrono::milliseconds(500));
    });

    Graph<float> g;
    g.addNode(&A);
    g.addNode(&B);
    g.addNode(&C);
    g.addNode(&D);
    g.addNode(&E);
    g.addNode(&F);
    g.addNode(&G);
    g.addNode(&H);
    g.addNode(&I);
    g.addNode(&L);
    g.addNode(&M);
    g.addNode(&N);
    g.addNode(&O);
    g.addNode(&P);
    g.addNode(&Q);
    g.addNode(&R);
    g.addNode(&S);
    g.addNode(&T);



    MDFRepo<float> Repo;
    Repo.addGraph(&g);
    Repo.startEmitter(nTasks, false);

    START(start);
    Repo.startFlow(nWorkers);
    STOP(start, end);
    std::cout << end << std::endl;

}

    return 0;
}