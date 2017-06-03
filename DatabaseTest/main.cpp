#include "logingui.h"
#include <QApplication>
#include "pthread.h"
#include "Common.h"

extern "C++"
{
 #ifdef USE_LINUX
#include "Algo.h"
#include "myKeypadScanning.h"
#include "client.h"
#endif

}


int main(int argc, char *argv[])
{

       QApplication a(argc, argv);
        #ifdef USE_LINUX
           algoMain();
           ClientSetup();
         #endif

           LoginGui w;
           w.show();
           return a.exec();

}
