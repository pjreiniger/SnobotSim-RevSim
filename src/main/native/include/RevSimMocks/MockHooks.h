

#include <stdint.h>

#include "RevMockUtilities.h"

namespace SnobotSim
{

typedef void (*REV_CallbackFunc)(const char* name, uint32_t messageId,
        uint8_t* buffer, int size);

void EXPORT_ SetSparkMaxDriverCallback(REV_CallbackFunc callback);

}  // namespace SnobotSim
