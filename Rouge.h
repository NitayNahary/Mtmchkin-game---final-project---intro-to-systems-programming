#ifndef HW4_ROUGE_H
#define HW4_ROUGE_H


#include "Player.h"

class Rouge : public Player {
public:
    explicit Rouge(const char* name);
    Rouge& operator=(const Rouge& src) = default;
    Rouge(const Rouge& src) = default;
    ~Rouge() override = default;

//--------------------------------------------------------------------------------------------------------------------//
    void addCoins(const int coinUp) override;
    string getClass() const override;

};

#endif //HW4_ROUGE_H
