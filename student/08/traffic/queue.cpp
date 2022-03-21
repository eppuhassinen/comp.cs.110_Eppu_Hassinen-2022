#include "queue.hh"

// Implement the member functions of Queue here

Queue::Queue(unsigned int cycle)
{
    cycle_ = cycle;
}

Queue::~Queue()
{

}

void Queue::enqueue(const string &reg)
{
    if (is_green_)
    {
        cout << "GREEN: The vehicle " << reg << " need not stop to wait" << endl;
        ++cars_through_;
        if (cars_through_ >= cycle_)
        {
            is_green_ = false;
        }
        return;
    }
    if (first_ == nullptr)
    {
        first_ = new Vehicle({reg, nullptr});
        last_ = first_;
        return;
    }

    last_->next = new Vehicle({reg, nullptr});
    last_ = last_->next;

}

void Queue::switch_light()
{
    is_green_ = !is_green_;
    print();

    if (is_green_)
    {
        cars_through_ = 0;

        for(unsigned int i = cars_through_; i < cycle_; ++i)
        {
            if (!dequeue())
            {

                return;
            }
            ++cars_through_;
        }

        is_green_ = false;
        cars_through_ = 0;
    }

}

void Queue::reset_cycle(unsigned int cycle)
{
    cycle_ = cycle;
}

void Queue::print() const
{
    string light = "RED:";
    if (is_green_)
    {
        light = "GREEN:";
    }
    if (first_ == nullptr)
    {
        cout << light << " No vehicles waiting in traffic lights" << endl;
        return;
    }
    auto current_car = first_;
    if (is_green_)
    {
        cout << light << " Vehicle(s)";
        for (unsigned int i = cars_through_; i < cycle_; ++i)
        {
            if (current_car != nullptr)
            {
                cout << " " << current_car->reg_num;
                current_car = current_car->next;
            }
        }
        cout << " can go on" << endl;
    }
    if (!is_green_)
    {
        cout << light << " Vehicle(s)";
        while (current_car != nullptr)
        {
                cout << " " << current_car->reg_num;
                current_car = current_car->next;

        }
        cout << " waiting in traffic lights" << endl;
    }
}

bool Queue::dequeue()
{
    if (first_ == nullptr)
    {
        return false;
    }

    auto item_to_be_removed = first_;

    first_ = first_->next;

    delete item_to_be_removed;

    return true;
}
