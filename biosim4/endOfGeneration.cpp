// endOfGeneration.cpp

#include <iostream>
#include <utility>
#include <cassert>
#include <cstdlib>
#include <algorithm>
#include "simulator.h"
#include "imageWriter.h"

namespace BS {

// At the end of each generation, we save a video file (if p.saveVideo is true) and
// print some genomic statistics to stdout (if p.updateGraphLog is true).

void endOfGeneration(unsigned generation)
{
    {
        if (p.saveVideo &&
                ((generation % p.videoStride) == 0
                 || generation <= p.videoSaveFirstFrames
                 || (generation >= p.parameterChangeGenerationNumber
                     && generation <= p.parameterChangeGenerationNumber + p.videoSaveFirstFrames))) {
            imageWriter.saveGenerationVideo(generation);
        }
    }
}

} // end namespace BS
