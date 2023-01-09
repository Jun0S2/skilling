#include <cstdint>
#include <map>
#include "DisplayManager.h"

enum class ScreenType : uint32_t {
   FRONT
};

enum class DisplayStatus : uint32_t {
    Off,
    On,
    Count
};

class DisplayManagerProtocol {
public:
    DisplayManagerProtocol() {}
    ~DisplayManagerProtocol() {}

    void setDisplayManagerProtocol(const ScreenType& _screen, const DisplayStatus& _status, const bool& _forced_off, const uint32_t& _pid) {
        m_DisplayStatusMap[_screen] = _status;
        forcedOff = _forced_off;
        pid = _pid;
    }

    bool getDisplayStatus(const ScreenType& _screen) {
        // Check if the display status for the given screen exists in the map
        if (m_DisplayStatusMap.find(_screen) == m_DisplayStatusMap.end()) {
            return false;
        }
        // Return the display status for the given screen
        return m_DisplayStatusMap[_screen] == DisplayStatus::On;
    }

private:
    std::map<ScreenType, DisplayStatus> m_DisplayStatusMap;
    bool forcedOff;
    uint32_t pid;
};

namespace ccos {
namespace device{
namespace displayservice {
    bool DisplayManager::initDisplayStatus(const ScreenType& screen) {
        DisplayManagerProtocol displayManagerProtocol;
        displayManagerProtocol.setDisplayManagerProtocol(ScreenType::FRONT, DisplayStatus::Off,false,0);
    }
    

}
} // namespace devic
}