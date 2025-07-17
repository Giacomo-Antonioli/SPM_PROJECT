//
// Created by giaco on 06/07/2022.
//

#ifndef SPM_DESTINATION_TOKEN_H
#define SPM_DESTINATION_TOKEN_H


class Destination_Token {
public:
    int index_of_current_output;
    int destination_MDFI;
    int position_in_destination_token_list;

    Destination_Token(int index_of_current_output = 0, int destination_MDFI = 0,
                      int position_in_destination_token_list = 0);

private:

};


#endif //SPM_DESTINATION_TOKEN_H
