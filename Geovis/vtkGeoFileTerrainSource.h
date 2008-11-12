/*=========================================================================

  Program:   Visualization Toolkit
  Module:    vtkGeoFileTerrainSource.h

  Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
/*-------------------------------------------------------------------------
  Copyright 2008 Sandia Corporation.
  Under the terms of Contract DE-AC04-94AL85000 with Sandia Corporation,
  the U.S. Government retains certain rights in this software.
-------------------------------------------------------------------------*/
// .NAME vtkGeoFileTerrainSource - A source for tiled geometry on disk.
//
// .SECTION Description
// vtkGeoFileTerrainSource reads geometry tiles as .vtp files from a
// directory that follow a certain naming convention containing the level
// of the patch and the position within that level. Use vtkGeoTerrain's
// SaveDatabase method to create a database of files in this format.

#include "vtkGeoSource.h"
#include "vtkSmartPointer.h" // For smart pointer ivars

class vtkGeoTerrainNode;
class vtkGeoTreeNode;

class VTK_GEOVIS_EXPORT vtkGeoFileTerrainSource : public vtkGeoSource
{
public:
  static vtkGeoFileTerrainSource *New();
  vtkTypeRevisionMacro(vtkGeoFileTerrainSource,vtkGeoSource);

  vtkGeoFileTerrainSource();
  ~vtkGeoFileTerrainSource();

  // Description:
  // Retrieve the root geometry representing the entire globe.
  virtual bool FetchRoot(vtkGeoTreeNode* root);

  // Decription:
  // Retreive the child's geometry from disk.
  virtual bool FetchChild(vtkGeoTreeNode* node, int index, vtkGeoTreeNode* child);

  // Description:
  // The path the tiled geometry database.
  vtkSetStringMacro(Path);
  vtkGetStringMacro(Path);

protected:

  bool ReadModel(int level, int id, vtkGeoTerrainNode* node);

private:
  vtkGeoFileTerrainSource(const vtkGeoFileTerrainSource&); // Not implemented
  void operator=(const vtkGeoFileTerrainSource&); // Not implemented

  char* Path;
};

