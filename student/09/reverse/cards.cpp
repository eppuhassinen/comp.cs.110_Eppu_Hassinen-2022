#include <iostream>
#include <memory>
#include "cards.hh"
#include <iostream>

Cards::Cards(): top_( nullptr ) {
}


void Cards::add(int id) {
    std::shared_ptr<Card_data> new_card 
            = std::make_shared<Card_data>(Card_data{id, top_});
    top_ = new_card;
}

void Cards::print(std::ostream& s) {
   std::shared_ptr<Card_data> to_be_printed = top_;
   int nr = 1;

   while( to_be_printed != 0 ) {
      s << nr << ": " << to_be_printed->data << std::endl;
      to_be_printed = to_be_printed->next;
      ++nr;
   }
}

bool Cards::remove(int &id)
{
    if (top_ == nullptr)
    {
        return false;
    }

    id = top_->data;
    top_ = top_->next;
    return true;
}

void Cards::reverse()
{
    std::shared_ptr<Card_data> middle = top_;
    std::shared_ptr<Card_data> next = nullptr;
    top_ = top_->next;

    while (top_ != nullptr)
    {
        middle->next = next;
        next = middle;

        middle = top_;
        top_ = top_->next;
    }

    top_ = middle;
    top_->next = next;
}
