/* ****************************************************************** **
**    OpenSees - Open System for Earthquake Engineering Simulation    **
**          Pacific Earthquake Engineering Research Center            **
**                                                                    **
**                                                                    **
** (C) Copyright 2001, The Regents of the University of California    **
** All Rights Reserved.                                               **
**                                                                    **
** Commercial use of this program without express permission of the   **
** University of California, Berkeley, is strictly prohibited.  See   **
** file 'COPYRIGHT'  in main directory for information on usage and   **
** redistribution,  and for a DISCLAIMER OF ALL WARRANTIES.           **
**                                                                    **
** Developed by:                                                      **
**   Frank McKenna (fmckenna@ce.berkeley.edu)                         **
**   Gregory L. Fenves (fenves@ce.berkeley.edu)                       **
**   Filip C. Filippou (filippou@ce.berkeley.edu)                     **
**                                                                    **
** Fire & Heat Transfer modules developed by:                         **
**   Yaqiang Jiang (y.jiang@ed.ac.uk)                                 **
**   Asif Usmani (asif.usmani@ed.ac.uk)                               **
**                                                                    **
** ****************************************************************** */

//
// Written by Yaqiang Jiang (y.jiang@ed.ac.uk)
//
// Note: This class was adapted from FE_EleIter 
#include <HT_FE_EleIter.h>

#include <HT_FE_Element.h>
#include <TaggedObjectIter.h>
#include <TaggedObjectStorage.h>


// FE_EleIter(SingleDomain &theDomain):
//	constructor that takes the model, just the basic iter

HT_FE_EleIter::HT_FE_EleIter(TaggedObjectStorage* theStorage)
:myIter(&(theStorage->getComponents()))
{

}


HT_FE_EleIter::~HT_FE_EleIter()
{
}    

void
HT_FE_EleIter::reset(void)
{
    myIter->reset();
}    


HT_FE_Element*
HT_FE_EleIter::operator()(void)
{
    // check if we still have elements in the model
    // if not return 0, indicating we are done
    TaggedObject *theComponent = (*myIter)();
    if (theComponent == 0)
		return 0;
    else {
		HT_FE_Element* result = (HT_FE_Element *)theComponent;
		return result;
    }
}