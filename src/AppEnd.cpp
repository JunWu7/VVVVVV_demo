#include "App.hpp"
#include"Util/Logger.hpp"

void App::End() { // NOLINT(this method will mutate members in the future)
    LOG_TRACE("End");
    m_Player.reset();
    m_LM.reset();
    m_Map.reset();
}
