#pragma once

#include "../ld2420e.h"
#include "esphome/components/binary_sensor/binary_sensor.h"

namespace esphome
{
  namespace ld2420e
  {

    class LD2420EBinarySensor : public LD2420EListener, public Component, binary_sensor::BinarySensor
    {
    public:
      void dump_config() override;
      void set_presence_sensor(binary_sensor::BinarySensor *bsensor) { this->presence_bsensor_ = bsensor; };
      void on_presence(bool presence) override
      {
        if (this->presence_bsensor_ != nullptr)
        {
          if (this->presence_bsensor_->state != presence)
            this->presence_bsensor_->publish_state(presence);
        }
      }

    protected:
      binary_sensor::BinarySensor *presence_bsensor_{nullptr};
    };

  } // namespace ld2420e
} // namespace esphome
