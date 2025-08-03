#include "toshiba_climate_mode.h"
#include "esphome/components/climate/climate.h"
#include "esphome/core/log.h"
#include "toshiba_climate.h"

namespace esphome {
namespace toshiba_suzumi {

const MODE ClimateModeToInt(climate::ClimateMode mode) {
  switch (mode) {
    case climate::CLIMATE_MODE_HEAT_COOL:
      return MODE::HEAT_COOL;
    case climate::CLIMATE_MODE_COOL:
      return MODE::COOL;
    case climate::CLIMATE_MODE_HEAT:
      return MODE::HEAT;
    case climate::CLIMATE_MODE_DRY:
      return MODE::DRY;
    case climate::CLIMATE_MODE_FAN_ONLY:
      return MODE::FAN_ONLY;
    default:
      ESP_LOGE(TAG, "Invalid climate mode.");
      return MODE::HEAT_COOL;
  }
}

const climate::ClimateMode IntToClimateMode(MODE mode) {
  switch (mode) {
    case MODE::HEAT_COOL:
      return climate::CLIMATE_MODE_HEAT_COOL;
    case MODE::COOL:
      return climate::CLIMATE_MODE_COOL;
    case MODE::HEAT:
      return climate::CLIMATE_MODE_HEAT;
    case MODE::DRY:
      return climate::CLIMATE_MODE_DRY;
    case MODE::FAN_ONLY:
      return climate::CLIMATE_MODE_FAN_ONLY;
    default:
      ESP_LOGE(TAG, "Invalid climate mode.");
      return climate::CLIMATE_MODE_OFF;
  }
}

const optional<FAN> StringToFanLevel(std::string mode) {
  if (mode == CUSTOM_FAN_LEVEL_2) {
    return FAN::FANMODE_2;
  } else if (mode == CUSTOM_FAN_LEVEL_4) {
    return FAN::FANMODE_4;
  } else {
    return nullopt;
  }
}

const std::string IntToCustomFanMode(FAN mode) {
  switch (mode) {
    case FAN::FANMODE_2:
      return CUSTOM_FAN_LEVEL_2;
    case FAN::FANMODE_4:
      return CUSTOM_FAN_LEVEL_4;
    default:
      return "Unknown";
  }
}

const optional<PWR_LEVEL> StringToPwrLevel(const std::string &mode) {
  if (str_equals_case_insensitive(mode, CUSTOM_PWR_LEVEL_OFF)) {
    return PWR_LEVEL::OFF;
  } else if (str_equals_case_insensitive(mode, CUSTOM_PWR_LEVEL_BOTH)) {
    return PWR_LEVEL::BOTH;
  } else if (str_equals_case_insensitive(mode, CUSTOM_PWR_LEVEL_VERTICAL)) {
    return PWR_LEVEL::VERTICAL;
  } else if (str_equals_case_insensitive(mode, CUSTOM_PWR_LEVEL_HORIZONTAL)) {
    return PWR_LEVEL::HORIZONTAL;
  } else if (str_equals_case_insensitive(mode, CUSTOM_PWR_LEVEL_1)) {
    return PWR_LEVEL::FIX_POS_1;
  } else if (str_equals_case_insensitive(mode, CUSTOM_PWR_LEVEL_2)) {
    return PWR_LEVEL::FIX_POS_2;
  } else if (str_equals_case_insensitive(mode, CUSTOM_PWR_LEVEL_3)) {
    return PWR_LEVEL::FIX_POS_3;
  } else if (str_equals_case_insensitive(mode, CUSTOM_PWR_LEVEL_4)) {
    return PWR_LEVEL::FIX_POS_4;
  } else if (str_equals_case_insensitive(mode, CUSTOM_PWR_LEVEL_5)) {
    return PWR_LEVEL::FIX_POS_5;
  } else {
    return nullopt;
  }
}

const std::string IntToPowerLevel(PWR_LEVEL mode) {
  switch (mode) {
    case PWR_LEVEL::OFF:
      return CUSTOM_PWR_LEVEL_OFF;
    case PWR_LEVEL::BOTH:
      return CUSTOM_PWR_LEVEL_BOTH;
    case PWR_LEVEL::VERTICAL:
      return CUSTOM_PWR_LEVEL_VERTICAL;
    case PWR_LEVEL::HORIZONTAL:
      return CUSTOM_PWR_LEVEL_HORIZONTAL;
    case PWR_LEVEL::FIX_POS_1:
      return CUSTOM_PWR_LEVEL_1;
    case PWR_LEVEL::FIX_POS_2:
      return CUSTOM_PWR_LEVEL_2;
    case PWR_LEVEL::FIX_POS_3:
      return CUSTOM_PWR_LEVEL_3;
    case PWR_LEVEL::FIX_POS_4:
      return CUSTOM_PWR_LEVEL_4;
    case PWR_LEVEL::FIX_POS_5:
      return CUSTOM_PWR_LEVEL_5;
    default:
      return "Unknown";
  }
}

const optional<SPECIAL_MODE> SpecialModeToInt(const std::string &mode) {
  if (str_equals_case_insensitive(mode, SPECIAL_MODE_STANDARD)) {
    return SPECIAL_MODE::STANDARD;
  } else if (str_equals_case_insensitive(mode, SPECIAL_MODE_HI_POWER)) {
    return SPECIAL_MODE::HI_POWER;
  } else if (str_equals_case_insensitive(mode, SPECIAL_MODE_ECO)) {
    return SPECIAL_MODE::ECO;
  } else if (str_equals_case_insensitive(mode, SPECIAL_MODE_FIREPLACE_1)) {
    return SPECIAL_MODE::FIREPLACE_1;
  } else if (str_equals_case_insensitive(mode, SPECIAL_MODE_FIREPLACE_2)) {
    return SPECIAL_MODE::FIREPLACE_2;
  } else if (str_equals_case_insensitive(mode, SPECIAL_MODE_EIGHT_DEG)) {
    return SPECIAL_MODE::EIGHT_DEG;
  } else if (str_equals_case_insensitive(mode, SPECIAL_MODE_SILENT_1)) {
    return SPECIAL_MODE::SILENT_1;
  } else if (str_equals_case_insensitive(mode, SPECIAL_MODE_SILENT_2)) {
    return SPECIAL_MODE::SILENT_2;
  } else if (str_equals_case_insensitive(mode, SPECIAL_MODE_SLEEP)) {
    return SPECIAL_MODE::SLEEP;
  } else if (str_equals_case_insensitive(mode, SPECIAL_MODE_FLOOR)) {
    return SPECIAL_MODE::FLOOR;
  } else if (str_equals_case_insensitive(mode, SPECIAL_MODE_COMFORT)) {
    return SPECIAL_MODE::COMFORT;
  } else {
    return SPECIAL_MODE::STANDARD;
  }
}

const std::string IntToSpecialMode(SPECIAL_MODE mode) {
  switch (mode) {
    case SPECIAL_MODE::STANDARD:
      return SPECIAL_MODE_STANDARD;
    case SPECIAL_MODE::HI_POWER:
      return SPECIAL_MODE_HI_POWER;
    case SPECIAL_MODE::ECO:
      return SPECIAL_MODE_ECO;
    case SPECIAL_MODE::FIREPLACE_1:
      return SPECIAL_MODE_FIREPLACE_1;
    case SPECIAL_MODE::FIREPLACE_2:
      return SPECIAL_MODE_FIREPLACE_2;
    case SPECIAL_MODE::EIGHT_DEG:
      return SPECIAL_MODE_EIGHT_DEG;
    case SPECIAL_MODE::SILENT_1:
      return SPECIAL_MODE_SILENT_1;
    case SPECIAL_MODE::SILENT_2:
      return SPECIAL_MODE_SILENT_2;
    case SPECIAL_MODE::SLEEP:
      return SPECIAL_MODE_SLEEP;
    case SPECIAL_MODE::FLOOR:
      return SPECIAL_MODE_FLOOR;
    case SPECIAL_MODE::COMFORT:
      return SPECIAL_MODE_COMFORT;
    default:
      return "Unknown";
  }
}

const LogString *climate_state_to_string(STATE mode) {
  switch (mode) {
    case STATE::ON:
      return LOG_STR("ON");
    case STATE::OFF:
      return LOG_STR("OFF");
    default:
      return LOG_STR("UNKNOWN");
  }
}

}  // namespace toshiba_suzumi
}  // namespace esphome
