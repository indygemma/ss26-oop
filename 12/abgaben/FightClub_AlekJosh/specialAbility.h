#ifndef SPECIALABILITY_H
#define SPECIALABILITY_H

#include "Ability.h"


class specialAbility : public Ability
{
    public:
        specialAbility(string name, int damage);
        virtual ~specialAbility();

        void execute(Character& source, Character& target) override;

    protected:

    private:
};

#endif // SPECIALABILITY_H
