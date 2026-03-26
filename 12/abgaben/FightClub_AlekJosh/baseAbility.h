#ifndef BASEABILITY_H
#define BASEABILITY_H

#include "Ability.h"


class baseAbility : public Ability
{
    public:
        baseAbility(string name, int damage);
        virtual ~baseAbility();

        void execute(Character& source, Character& target) override;

    protected:

    private:
};

#endif // BASEABILITY_H
