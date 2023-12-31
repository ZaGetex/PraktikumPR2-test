/* 
 * File:   simfeedpusher.cpp
 * @author Lehmann
 * @date 22. Mai 2020
 */

#include "simfeedpusher.h"

bool SimFeedPusher::isModePassing() {
    bool result = false;
    if (state != nullptr) {
        // if set, pushed out, no passing
        result = !((state->out & SIM_BITMASK_FEEDSEPERATOR_ACTOR) == SIM_BITMASK_FEEDSEPERATOR_ACTOR);  
        if (result) {
            state->in = (state->in | SIM_BITMASK_FEEDSEPERATOR_SENSOR);
        } else {
            state->in = (state->in & (~SIM_BITMASK_FEEDSEPERATOR_SENSOR));
        }
    }
    return result;
}
