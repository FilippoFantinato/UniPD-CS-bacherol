//
// Created by Alberto Sinigaglia on 19/01/2020.
//

#ifndef LIBRERIELEZIONI_WORKOUT_H
#define LIBRERIELEZIONI_WORKOUT_H
class Workout{
private:
    unsigned int minuti;
public:
    virtual Workout* clone() const = 0;
    virtual unsigned int calorie() const = 0;
    virtual ~Workout() = default;
    unsigned int durata() const{
        return minuti;
    }
};
#endif //LIBRERIELEZIONI_WORKOUT_H
