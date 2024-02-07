#include <iostream>
#include <signal.h>
void signal_callback_handler(int signum) {
   std::cout << "Caught signal " << signum << std::endl;
   exit(signum);
}
int main(){
   signal(SIGINT, signal_callback_handler);
   while(true){
      std::cout << "processing..." << std::endl;
      sleep(1);
   }
   return EXIT_SUCCESS;
}
