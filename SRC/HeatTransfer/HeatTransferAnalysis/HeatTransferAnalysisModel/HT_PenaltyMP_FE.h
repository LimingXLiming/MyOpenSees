/* ****************************************************************** **
**    OpenSees - Open System for Earthquake Engineering Simulation    **
**          Pacific Earthquake Engineering Research Center            **
**                                                                    **
**                                                                    **
** (C) Copyright 1999, The Regents of the University of California    **
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
** ****************************************************************** */
                                                                        
// $Revision: 1.4 $
// $Date: 2006-02-08 20:20:00 $
// $Source: /usr/local/cvs/OpenSees/SRC/analysis/fe_ele/penalty/HT_PenaltyMP_FE.h,v $
                                                                        
                                                                        
#ifndef HT_PenaltyMP_FE_h
#define HT_PenaltyMP_FE_h

// Written: fmk 
// Created: 11/96
// Revision: A
//
// Description: This file contains the class definition for HT_PenaltyMP_FE.
// HT_PenaltyMP_FE is a subclass of FE_Element which handles MP_Constraints
// using the penalty method.
//
// What: "@(#) HT_PenaltyMP_FE.h, revA"

#include <HT_FE_Element.h>
#include <ID.h>
#include <Matrix.h>
#include <Vector.h>

class HeatTransferElement;
class HeatTransferIntegrator;
class HT_TransientIntegrator;
class HT_AnalysisModel;
class HeatTransferDomain;
class MP_TemperatureBC;
class HeatTransferNode;

class HT_PenaltyMP_FE: public HT_FE_Element
{
  public:
    HT_PenaltyMP_FE(int tag, HeatTransferDomain &theDomain, MP_TemperatureBC &theMP, double alpha);
   virtual  ~HT_PenaltyMP_FE();    

    // public methods
    virtual int  setID(void);
    virtual const Matrix &getTangent(HeatTransferIntegrator *theIntegrator);
    virtual const Vector &getResidual(HeatTransferIntegrator *theIntegrator);
    virtual const Vector &getTangForce(const Vector &x, double fact = 1.0);

    virtual const Vector &getK_Force(const Vector &x, double fact = 1.0);
    virtual const Vector &getKi_Force(const Vector &x, double fact = 1.0);
    virtual const Vector &getC_Force(const Vector &x, double fact = 1.0);
    virtual const Vector &getM_Force(const Vector &x, double fact = 1.0);
    
  protected:
    
  private:
    void determineTangent(void);
    
    MP_TemperatureBC* theMP;
    HeatTransferNode* theConstrainedNode;
    HeatTransferNode* theRetainedNode;    

    Matrix *tang;
    Vector *resid;
    Matrix *C;    // to hold the C matrix
    double alpha;
	
    
};

#endif


