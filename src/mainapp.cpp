#include <string>
#include <cstring>
#include <iostream>
#include <cstdio>
#include "write_text/write_text.h"
#include "file_lib.h"


int main(int argc, char *argv[]){
   
   if(argc==1) return 0;
   
   bool outputfile=false;
   bool inputfile=false;
   std::string path;
   // Check Input Parameters
   for(int i=1;i<argc;i++) {
      
      if(std::strcmp(argv[i],"-h")==0 || std::strcmp(argv[i],"--help")==0) {
         std::cout << "Help info" <<"\n";
         return 0;
      }
      else if(std::strcmp(argv[i],"-o")==0) {
         outputfile=true;
      }
      else if(std::strchr(argv[i],'-')) {
         std::cout << "Unknown command: " <<argv[i]<<"\n";
         return 0;
      } 
      else {
         if(inputfile) {
            std::cout << "Only one input file is possible!\n";
            return 0;
         }
         inputfile=true;
         path=argv[i];
      }
   }
   // Read string
   std::string text;
   read_string(path,text);
   if(outputfile) {
      // write string to disk
      path = path + ".out";
      std::remove(path.c_str());
      write_string(path,text);
      std::cout << "Output written in file " << path << std::endl; 
   }
   else{
      // print string in terminal
      TextMessage m(text);
      m.write_message();   
   }

   return 0;
}



