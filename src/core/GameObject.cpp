//
// Created by seth on 6/8/20.
//

#include "core/GameObject.h"

uint32_t GameObject::getId()
{
  return id;
}

void GameObject::setId(uint32_t id)
{
  this->id = id;
}