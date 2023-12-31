
/* 
 * File:   simconveyorbelt.h
 * @author Lehmann
 * @date 3. April 2020
 */

#ifndef SIMCONVEYORBELT_H
#define SIMCONVEYORBELT_H

#include "simbase.h"
#include "isimdrophandler.h"
#include "simslide.h"
#include "simdrive.h"
#include "isimseparator.h"
#include "simitem.h"

#include <vector>
#include <memory>

class SimConveyorBelt{
private:
    std::vector<std::shared_ptr<SimItem>> *items;
    SimSlide *slide;
    SimDrive *drive;
    ISimSeparator *separator;
    double speedX;
    double speedY;
    ISimDropHandler *dh;
    int displayCounter;
    bool previousMode;
public:
    SimConveyorBelt(std::vector<std::shared_ptr<SimItem>> *items, SimSlide *slide, SimDrive *drive, ISimSeparator *separator);
    void addItem(const std::shared_ptr<SimItem> &item);
    void evalTimeStep(unsigned int simTime);
    void setDropHandler(ISimDropHandler* dh);
};

#endif /* SIMCONVEYORBELT_H */

