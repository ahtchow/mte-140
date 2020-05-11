#include <iostream>
#include <string>
using namespace std; 

/**
 * @brief Use recursion to check if original message is in garbled_text
 * If the message is contained in the text without changing order , then return number of extra characters past original
 * If message is not in the text return -1;
 * run /erfuinnns -> return 6
 * 
 */

int has_original_message(string message, string garbled_text){
    int size1 = message.length();
    int size2 = garbled_text.length();
    bool hasOriginal = true;
    hasOriginal = has_original_message1(message,garbled_text,size1, size2,0);
    if(hasOriginal)
        return (size2 -size1);
    else {
        return -1; 
    }
}

bool has_original_message1(string message, string text, int size1, int size2, int distance){
    if(size1 == distance)
        return true;
    if(message.empty() || size1  == 0)
        return true;
    if(text.empty() || size2  == 0)
        return true;
    else{
        for( int i = distance; i < size2 ;i++){
            if(message[distance] == text[i]){
                return has_original_message1(message, text, size1, size2, ++distance);
            }
         }
        return false;
    }
}

int main(){
    string msg = "hellos";
    string lost = "helleoleabhel";

    cout << has_original_message1(msg, lost, msg.length(), lost.length(), 0);

}