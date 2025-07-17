//
// Created by giaco on 06/07/2022.
//

#include "Destination_Token.h"

Destination_Token::Destination_Token(int index_of_current_output, int destination_MDFI,
                                     int position_in_destination_token_list) {
    Destination_Token::index_of_current_output = index_of_current_output;
    Destination_Token::destination_MDFI = destination_MDFI;
    Destination_Token::position_in_destination_token_list = position_in_destination_token_list;
}