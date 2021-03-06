//////////////////////////////////////////////////////////////////////////////////////
// This file is distributed under the University of Illinois/NCSA Open Source License.
// See LICENSE file in top directory for details.
//
// Copyright (c) 2016 Jeongnim Kim and QMCPACK developers.
//
// File developed by: Jeremy McMinnis, jmcminis@gmail.com, University of Illinois at Urbana-Champaign
//                    Jaron T. Krogel, krogeljt@ornl.gov, Oak Ridge National Laboratory
//                    Mark A. Berrill, berrillma@ornl.gov, Oak Ridge National Laboratory
//
// File created by: Jeremy McMinnis, jmcminis@gmail.com, University of Illinois at Urbana-Champaign
//////////////////////////////////////////////////////////////////////////////////////
    
    

#ifndef AFM_SPO_BUILDER_H
#define AFM_SPO_BUILDER_H

#include "QMCWaveFunctions/BasisSetBase.h"
#include "QMCWaveFunctions/AFMSPOSet.h"


namespace qmcplusplus
{
class AFMSPOBuilder : public BasisSetBuilder
{
protected:
  typedef std::map<std::string,ParticleSet*> PtclPoolType;
  typedef std::map<std::string,SPOSetBase*>  SPOPoolType;
  ParticleSet *targetPtcl;
public:
  AFMSPOBuilder(ParticleSet& p, PtclPoolType& psets,
                xmlNodePtr cur);

  bool put (xmlNodePtr cur);

  /** initialize the Antisymmetric wave function for electrons
   *@param cur the current xml node
   */
  SPOSetBase* createSPOSetFromXML(xmlNodePtr cur);
  //    SPOSetBase* createSPOSetFromXML(xmlNodePtr cur, SPOPool_t& spo_pool);

};
}

#endif
