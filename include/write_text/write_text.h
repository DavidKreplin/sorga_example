#ifndef _WRITE_TEXT_H
#define _WRITE_TEXT_H

#include <string>

/** @defgroup tm_group Text Message Module 
 *  The module TextMessage consists functions for printing text to the terminal
 *  
 *  To write a with this module use the constructor TextMessage() and its
 *  member function TextMessage::write_message() 
 * 
 *  @{
 */

class TextMessage{
private:
	std::string message;
public:
	/** @brief Initialization with a string
	 *
	 * Constructor, stores the text message in a private variable
	 *
	 * @param message String with the text message
         */
	TextMessage(std::string message);

	/** @brief Prints the text message
	 *
	 * Prints the text message in the terminal
	 *
	 */
	void write_message(); 
};

/** @} */
#endif
