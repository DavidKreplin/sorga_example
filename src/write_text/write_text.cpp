#include <iostream>
#include "write_text/write_text.h"

TextMessage::TextMessage(std::string message):message(message){}

void TextMessage::write_message(){
   std::cout << "This is your message: " 
      << std::endl << this->message << std::endl;
}

