g++ -o test_pool test_pool.cpp \
     ../thread_pool/thread_pool.h \
     ../thread_pool/thread_pool.cpp \
     ../tools/pthread_mutex.h \
     ../tools/pthread_cond.h \
     -I../../third-64/boost/include \
     -L../../third-64/boost/lib \
     -lpthread

     
g++ -o test_tools test_tools.cpp \
     ../tools/tools.h \
     ../tools/tools.cpp \
     -I../../third-64/boost/include \
     -L../../third-64/boost/lib \
     -lpthread
