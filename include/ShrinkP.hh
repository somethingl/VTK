//
// Class to shrink PolyData
//
#ifndef __vlShrinkPolyData_h
#define __vlShrinkPolyData_h

#include "P2PF.hh"

class vlShrinkPolyData : public vlPolyToPolyFilter 
{
public:
  vlShrinkPolyData() {this->ShrinkFactor = 0.5;};
  ~vlShrinkPolyData() {};
  char *GetClassName() {return "vlShrinkPolyData";};

  vlSetMacro(ShrinkFactor,float);
  vlGetMacro(ShrinkFactor,float);

protected:
  void Execute();
  float ShrinkFactor;
};

#endif


