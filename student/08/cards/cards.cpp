#include "cards.hh"

// TODO: Implement the methods here

Cards::Cards(): top_(nullptr)
{

}

Card_data *Cards::get_topmost()
{
    return top_;
}

void Cards::add(int id)
{
    if (top_ == nullptr)
    {
        top_ = new Card_data({id, nullptr});
    }
    else
    {
        Card_data *next_card = top_;
        top_ = new Card_data({id, next_card});
    }
}

void Cards::print_from_top_to_bottom(std::ostream &s)
{
    Card_data *current_card = top_;
    unsigned int running_number = 1;

    while(current_card != nullptr)
    {
        s << running_number << ": " << current_card->data << std::endl;
        ++running_number;
        current_card = current_card->next;
    }
}

bool Cards::remove(int &id)
{
    if (top_ == nullptr)
    {
        return false;
    }
    id = top_->data;
    Card_data *to_be_removed = top_;
    top_ = top_->next;
    delete to_be_removed;
    return true;
}

bool Cards::bottom_to_top()
{
    if (top_ == nullptr)
    {
        return false;
    }

    if (top_->next == nullptr)
    {
        return true;
    }
    Card_data *n_bottom = top_;

    while (n_bottom->next->next != nullptr)
    {
        n_bottom = n_bottom->next;
    }

    n_bottom->next->next = top_;
    top_ = n_bottom->next;

    n_bottom->next = nullptr;
    return true;


}

bool Cards::top_to_bottom()
{
    if (top_ == nullptr)
    {
        return false;
    }

    if (top_->next == nullptr)
    {
        return true;
    }
    Card_data *bottom = top_;

    while (bottom->next != nullptr)
    {
        bottom = bottom->next;
    }

    bottom->next = top_;
    top_ = top_->next;
    bottom->next->next = nullptr;
    return true;

}

void Cards::print_from_bottom_to_top(std::ostream &s)
{
    int running_number = 0;
    Card_data *current = top_;
    while (current != nullptr)
    {
        ++running_number;
        current = current->next;
    }

    recursive_print(top_, s, running_number);
    s << running_number << ": " << top_->data << std::endl;
}

Cards::~Cards()
{
    auto next_item = top_;
    while (next_item != nullptr)
    {
        next_item = top_->next;
        delete top_;
        top_ = next_item;
    }
}

int Cards::recursive_print(Card_data *top, std::ostream &s, int n)
{
    --n;
    if (top->next == nullptr)
    {
        return top->data;
    }
    int data_to_print = recursive_print(top->next, s, n);
    s << n << ": " << data_to_print << std::endl;

    return top->data;
}

