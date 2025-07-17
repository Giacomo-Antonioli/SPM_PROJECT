//
// Created by giaco on 18/05/2022.
//
#include <stdlib.h>
#include <iostream>
#include "Node.h"
#include "Graph.h"
#include <thread>
#include <chrono>
#include "utimer.cpp"
#include <cmath>
#include <stdlib.h>
#include <iostream>

#define GRA 2

int main(int argc, char *argv[]) {
    // std::cout<<"--------------------------------------------------"<<std::endl;
    int CYCLE = atoi(argv[1]);
    int nTasks = atoi(argv[2]);

    std::cout << nTasks << ", ";
    std::cout << CYCLE << ", ";

    if (GRA == 1) {
        Node A(1, 1, 5);//4
        Node B(2, 1, 2);//2
        Node C(3, 1, 1);
        Node D(4, 1, 1);
        Node E(5, 1, 1);
        Node F(6, 3, 1);
        Node G(7, 1, 1);
        Node H(8, 1, 1);
        Node I(9, 4, 1);


        A.addDep(&B);// A.addDep(&C);
        //B.addDep(&D); C.addDep(&D);
        //A.addDep(&B);
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

        A.addCompute(
                [CYCLE, &ab = A.outputs[0], &ac = A.outputs[1], &ad = A.outputs[2], &ae = A.outputs[3], &ai = A.outputs[4], &x = A.inputs[0]]() {
                    ae = x + 1;
                    ab = x + 1;
                    ac = x + 1;
                    ad = x + 1;
                    ai = 0;


                    ab = x + 1;
                    ac = x + 1;
                    ad = x + 1;
                    ae = x + 1;
                    ai = x + 1;
                    for (int i = 0; i < CYCLE; i++) {
                        ab = sin(sin(sin(ab)));
                        ac = cos(cos(sin(ac)));
                        ad = sin(tan(sin(ad))) + 3;
                        ae = sin(tan(sin(ae)));
                        ai = cos(cos(sin(ai))) + 5;
                    }
                });
        B.addCompute([CYCLE, &bg = B.outputs[0], &bh = B.outputs[1], &ba = B.inputs[0]]() {

            bg = ba + 1;
            bh = ba + 1;
            for (int i = 0; i < CYCLE; i++) {
                bg = sin(sin(sin(bg)));
                bh = cos(cos(sin(bh)));

            }
        });
        C.addCompute([CYCLE, &cf = C.outputs[0], &ca = C.inputs[0]]() {
            cf = ca + 1;
            for (int i = 0; i < CYCLE; i++) {

                cf = cos(cos(sin(cf))) + 5;
            }
        });
        D.addCompute([CYCLE, &df = D.outputs[0], &da = D.inputs[0]]() {

            df = da + 1;
            for (int i = 0; i < CYCLE; i++) {
                df = sin(sin(sin(df)));

            }
        });
        E.addCompute([CYCLE, &ef = E.outputs[0], &ea = E.inputs[0]]() {


            ef = ea + 1;

            for (int i = 0; i < CYCLE; i++) {
                ef = cos(cos(sin(ef)));

            }
        });
        F.addCompute([CYCLE, &fh = F.outputs[0], &fc = F.inputs[0], &fd = F.inputs[1], &fe = F.inputs[2]]() {
            fh = fc + fd + fe + 1;
            for (int i = 0; i < CYCLE; i++) {
                fh = cos(cos(sin(fh)));

            }
        });
        G.addCompute([CYCLE, &gh = G.outputs[0], &gb = G.inputs[0]]() {
            gh = gb + 1;
            for (int i = 0; i < CYCLE; i++) {
                gh = tan(cos(sin(gh)));

            }
        });
        H.addCompute([CYCLE, &ih = H.outputs[0], &ia = H.inputs[0]]() {
            ih = ia + 1;
            for (int i = 0; i < CYCLE; i++) {
                ih = sin(exp(sin(ih)));

            }

        });
        I.addCompute(
                [CYCLE, &res = I.outputs[0], &hb = I.inputs[0], &hg = I.inputs[1], &hf = I.inputs[2], &hi = I.inputs[3]]() {
                    res = hb + hf + hg + hi + 1;
                    for (int i = 0; i < CYCLE; i++) {
                        res = cos(cos(cos(hb))) + cos(cos(sin(hf))) + cos(tan(sin(hg))) + sin(cos(sin(hi)));

                    }

                });

        //  A.addCompute([&](){std::cout<<"CANEBAU"<<std::endl;});


        Graph g;
        g.addNode(&A);
        g.addNode(&B);
        g.addNode(&C);
        g.addNode(&D);
        g.addNode(&E);
        g.addNode(&F);
        g.addNode(&G);
        g.addNode(&H);
        g.addNode(&I);

        g.compute(nTasks);
        std::cout << "Result (x)" << std::endl;
        std::cout << g.result << std::endl;
    }
    if (GRA == 2) {
        Node A(1, 1, 1);//4
        Node B(2, 1, 1);//2
        Node C(3, 1, 1);
        Node D(4, 1, 1);
        Node E(5, 1, 1);
        Node F(6, 1, 1);
        Node G(7, 1, 1);
        Node H(8, 1, 1);
        Node I(9, 1, 1);
        Node L(10, 1, 1);//4
        Node M(11, 1, 1);//2
        Node N(12, 1, 1);
        Node O(13, 1, 1);
        Node P(14, 1, 1);
        Node Q(15, 1, 1);
        Node R(16, 1, 1);
        Node S(17, 1, 1);
        Node T(18, 1, 1);

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


        A.addCompute([CYCLE, &cf = A.outputs[0], &ca = A.inputs[0]]() {
            cf = ca + 1;
            for (int i = 0; i < CYCLE; i++) {

                cf = cos(cos(sin(cf))) + 5;
            }
        });

        B.addCompute([CYCLE, &cf = B.outputs[0], &ca = B.inputs[0]]() {
            cf = ca + 1;
            for (int i = 0; i < CYCLE; i++) {

                cf = cos(cos(sin(cf))) + 5;
            }
        });
        C.addCompute([CYCLE, &cf = C.outputs[0], &ca = C.inputs[0]]() {
            cf = ca + 1;
            for (int i = 0; i < CYCLE; i++) {

                cf = cos(cos(sin(cf))) + 5;
            }
        });
        D.addCompute([CYCLE, &cf = D.outputs[0], &ca = D.inputs[0]]() {
            cf = ca + 1;
            for (int i = 0; i < CYCLE; i++) {

                cf = cos(cos(sin(cf))) + 5;
            }
        });
        E.addCompute([CYCLE, &cf = E.outputs[0], &ca = E.inputs[0]]() {
            cf = ca + 1;
            for (int i = 0; i < CYCLE; i++) {

                cf = cos(cos(sin(cf))) + 5;
            }
        });
        F.addCompute([CYCLE, &cf = F.outputs[0], &ca = F.inputs[0]]() {
            cf = ca + 1;
            for (int i = 0; i < CYCLE; i++) {

                cf = cos(cos(sin(cf))) + 5;
            }
        });
        G.addCompute([CYCLE, &cf = G.outputs[0], &ca = G.inputs[0]]() {
            cf = ca + 1;
            for (int i = 0; i < CYCLE; i++) {

                cf = cos(cos(sin(cf))) + 5;
            }
        });
        H.addCompute([CYCLE, &cf = H.outputs[0], &ca = H.inputs[0]]() {
            cf = ca + 1;
            for (int i = 0; i < CYCLE; i++) {

                cf = cos(cos(sin(cf))) + 5;
            }
        });
        I.addCompute([CYCLE, &cf = I.outputs[0], &ca = I.inputs[0]]() {
            cf = ca + 1;
            for (int i = 0; i < CYCLE; i++) {

                cf = cos(cos(sin(cf))) + 5;
            }
        });
        L.addCompute([CYCLE, &cf = L.outputs[0], &ca = L.inputs[0]]() {
            cf = ca + 1;
            for (int i = 0; i < CYCLE; i++) {

                cf = cos(cos(sin(cf))) + 5;
            }
        });
        M.addCompute([CYCLE, &cf = M.outputs[0], &ca = M.inputs[0]]() {
            cf = ca + 1;
            for (int i = 0; i < CYCLE; i++) {

                cf = cos(cos(sin(cf))) + 5;
            }
        });
        N.addCompute([CYCLE, &cf = N.outputs[0], &ca = N.inputs[0]]() {
            cf = ca + 1;
            for (int i = 0; i < CYCLE; i++) {

                cf = cos(cos(sin(cf))) + 5;
            }
        });
        O.addCompute([CYCLE, &cf = O.outputs[0], &ca = O.inputs[0]]() {
            cf = ca + 1;
            for (int i = 0; i < CYCLE; i++) {

                cf = cos(cos(sin(cf))) + 5;
            }
        });
        P.addCompute([CYCLE, &cf = P.outputs[0], &ca = P.inputs[0]]() {
            cf = ca + 1;
            for (int i = 0; i < CYCLE; i++) {

                cf = cos(cos(sin(cf))) + 5;
            }
        });
        Q.addCompute([CYCLE, &cf = Q.outputs[0], &ca = Q.inputs[0]]() {
            cf = ca + 1;
            for (int i = 0; i < CYCLE; i++) {

                cf = cos(cos(sin(cf))) + 5;
            }
        });
        R.addCompute([CYCLE, &cf = R.outputs[0], &ca = R.inputs[0]]() {
            cf = ca + 1;
            for (int i = 0; i < CYCLE; i++) {

                cf = cos(cos(sin(cf))) + 5;
            }
        });
        S.addCompute([CYCLE, &cf = S.outputs[0], &ca = S.inputs[0]]() {
            cf = ca + 1;
            for (int i = 0; i < CYCLE; i++) {

                cf = cos(cos(sin(cf))) + 5;
            }
        });
        T.addCompute([CYCLE, &cf = T.outputs[0], &ca = T.inputs[0]]() {
            cf = ca + 1;
            for (int i = 0; i < CYCLE; i++) {

                cf = cos(cos(sin(cf))) + 5;
            }
        });


        Graph g;
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


        g.compute(nTasks);


    }
    if (GRA == 3) {
        Node A(1, 1, 16);//4
        Node B(2, 1, 1);//2
        Node C(3, 1, 1);
        Node D(4, 1, 1);
        Node E(5, 1, 1);
        Node F(6, 1, 1);
        Node G(7, 1, 1);
        Node H(8, 1, 1);
        Node I(9, 1, 1);
        Node L(10, 1, 1);//4
        Node M(11, 1, 1);//2
        Node N(12, 1, 1);
        Node O(13, 1, 1);
        Node P(14, 1, 1);
        Node Q(15, 1, 1);
        Node R(16, 1, 1);
        Node S(17, 1, 1);
        Node T(18, 16, 1);


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

        A.addCompute(
                [CYCLE, &a = A.inputs[0], &b = A.outputs[0], &c = A.outputs[1], &d = A.outputs[2], &e = A.outputs[3], &f = A.outputs[4], &g = A.outputs[5], &h = A.outputs[6], &si = A.outputs[7], &l = A.outputs[8], &m = A.outputs[9], &n = A.outputs[10], &o = A.outputs[11], &p = A.outputs[12], &q = A.outputs[13], &r = A.inputs[14], &s = A.outputs[15]]() {

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

                    //std::this_thread::sleep_for(std::chrono::milliseconds(500));
                });
        B.addCompute([CYCLE, &cf = B.outputs[0], &ca = B.inputs[0]]() {
            cf = ca + 1;
            for (int i = 0; i < CYCLE; i++) {

                cf = cos(cos(sin(cf))) + 5;
            }
        });
        C.addCompute([CYCLE, &cf = C.outputs[0], &ca = C.inputs[0]]() {
            cf = ca + 1;
            for (int i = 0; i < CYCLE; i++) {

                cf = cos(cos(sin(cf))) + 5;
            }
        });
        D.addCompute([CYCLE, &cf = D.outputs[0], &ca = D.inputs[0]]() {
            cf = ca + 1;
            for (int i = 0; i < CYCLE; i++) {

                cf = cos(cos(sin(cf))) + 5;
            }
        });
        E.addCompute([CYCLE, &cf = E.outputs[0], &ca = E.inputs[0]]() {
            cf = ca + 1;
            for (int i = 0; i < CYCLE; i++) {

                cf = cos(cos(sin(cf))) + 5;
            }
        });
        F.addCompute([CYCLE, &cf = F.outputs[0], &ca = F.inputs[0]]() {
            cf = ca + 1;
            for (int i = 0; i < CYCLE; i++) {

                cf = cos(cos(sin(cf))) + 5;
            }
        });
        G.addCompute([CYCLE, &cf = G.outputs[0], &ca = G.inputs[0]]() {
            cf = ca + 1;
            for (int i = 0; i < CYCLE; i++) {

                cf = cos(cos(sin(cf))) + 5;
            }
        });
        H.addCompute([CYCLE, &cf = H.outputs[0], &ca = H.inputs[0]]() {
            cf = ca + 1;
            for (int i = 0; i < CYCLE; i++) {

                cf = cos(cos(sin(cf))) + 5;
            }
        });
        I.addCompute([CYCLE, &cf = I.outputs[0], &ca = I.inputs[0]]() {
            cf = ca + 1;
            for (int i = 0; i < CYCLE; i++) {

                cf = cos(cos(sin(cf))) + 5;
            }
        });
        L.addCompute([CYCLE, &cf = L.outputs[0], &ca = L.inputs[0]]() {
            cf = ca + 1;
            for (int i = 0; i < CYCLE; i++) {

                cf = cos(cos(sin(cf))) + 5;
            }
        });
        M.addCompute([CYCLE, &cf = M.outputs[0], &ca = M.inputs[0]]() {
            cf = ca + 1;
            for (int i = 0; i < CYCLE; i++) {

                cf = cos(cos(sin(cf))) + 5;
            }
        });
        N.addCompute([CYCLE, &cf = N.outputs[0], &ca = N.inputs[0]]() {
            cf = ca + 1;
            for (int i = 0; i < CYCLE; i++) {

                cf = cos(cos(sin(cf))) + 5;
            }
        });
        O.addCompute([CYCLE, &cf = O.outputs[0], &ca = O.inputs[0]]() {
            cf = ca + 1;
            for (int i = 0; i < CYCLE; i++) {

                cf = cos(cos(sin(cf))) + 5;
            }
        });
        P.addCompute([CYCLE, &cf = P.outputs[0], &ca = P.inputs[0]]() {
            cf = ca + 1;
            for (int i = 0; i < CYCLE; i++) {

                cf = cos(cos(sin(cf))) + 5;
            }
        });
        Q.addCompute([CYCLE, &cf = Q.outputs[0], &ca = Q.inputs[0]]() {
            cf = ca + 1;
            for (int i = 0; i < CYCLE; i++) {

                cf = cos(cos(sin(cf))) + 5;
            }
        });
        R.addCompute([CYCLE, &cf = R.outputs[0], &ca = R.inputs[0]]() {
            cf = ca + 1;
            for (int i = 0; i < CYCLE; i++) {

                cf = cos(cos(sin(cf))) + 5;
            }
        });
        S.addCompute([CYCLE, &cf = S.outputs[0], &ca = S.inputs[0]]() {
            cf = ca + 1;
            for (int i = 0; i < CYCLE; i++) {

                cf = cos(cos(sin(cf))) + 5;
            }
        });
        T.addCompute(
                [CYCLE, &res = A.outputs[0], &b = A.inputs[0], &c = A.inputs[1], &d = A.inputs[2], &e = A.inputs[3], &f = A.inputs[4], &g = A.inputs[5], &h = A.inputs[6], &si = A.inputs[7], &l = A.inputs[8], &m = A.inputs[9], &n = A.inputs[10], &o = A.inputs[11], &p = A.inputs[12], &q = A.inputs[13], &r = A.inputs[14], &s = A.inputs[15]]() {


                    res = b + c + d + e + f + g + h + si + l + m + n + o + p + q + r + s;
                    for (int i = 0; i < CYCLE; i++) {

                        res = cos(cos(sin(res))) + 5;
                    }


                    //std::this_thread::sleep_for(std::chrono::milliseconds(500));
                });

        Graph g;
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


        g.compute(nTasks);

    }


    return 0;
}