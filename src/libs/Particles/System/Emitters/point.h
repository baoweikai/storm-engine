#ifndef POINT_EMITTER_H
#define POINT_EMITTER_H

#include "base.h"

class PointEmitter : public BaseEmitter
{
  protected:
    //Получить позицию для рождения новых партиклов
    Vector GetNewParticlePosition(float DeltaTime) override;

  public:
    // Конструктор / деструктор
    PointEmitter(ParticleSystem *pSystem);
    virtual ~PointEmitter();
};

#endif