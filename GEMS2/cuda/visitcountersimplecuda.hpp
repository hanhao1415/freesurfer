#pragma once

#include <vector>

#include "atlasmeshvisitcounter.hpp"

#include "dimensioncuda.hpp"

namespace kvl {
  namespace cuda {
    template<typename T>
    class VisitCounterSimple : public kvl::interfaces::AtlasMeshVisitCounter {
      virtual void SetRegions( const kvl::interfaces::AtlasMeshVisitCounter::ImageType::RegionType& region ) override {}

      virtual void VisitCount( const kvl::AtlasMesh* mesh ) override {

	std::vector<AtlasMesh::CellIdentifier> tetrahedronIds;

	// Find the tetrahedra
	for( auto cellIt = mesh->GetCells()->Begin();
	     cellIt != mesh->GetCells()->End();
	     ++cellIt ) {
	  if( cellIt.Value()->GetType() == AtlasMesh::CellType::TETRAHEDRON_CELL ) {
	    tetrahedronIds.push_back( cellIt.Index() );
	  }
	}

	std::cout << "Found " << tetrahedronIds.size() << " tetrahedra" << std::endl;

	// Extract co-ordinates
	Dimension<3, unsigned long> tetArrDims;
	std::vector<T> tetrahedra;
	tetArrDims[0] = tetrahedronIds.size();
	tetArrDims[1] = nVertices;
	tetArrDims[2] = nDims;
	tetrahedra.resize(tetArrDims.ElementCount());

	for( int iTet=0; iTet<tetrahedronIds.size(); iTet++ ) {
	  AtlasMesh::CellAutoPointer cell;
	  mesh->GetCell( tetrahedronIds.at(iTet), cell );

	  auto pit = cell->PointIdsBegin();
	  unsigned long iVertex = 0;
	  for( auto pit = cell->PointIdsBegin(); pit != cell->PointIdsEnd(); ++pit ) {
	    AtlasMesh::PointType p;
	    mesh->GetPoint( *pit, &p );

	    for( unsigned long i=0; i<nDims; i++ ) {
	      size_t idx = tetArrDims.GetLinearIndex((unsigned long)iTet,iVertex,i);
	      tetrahedra.at(idx) = p[i];
	    }

	    iVertex++;
	  }
	}
	std::cout << __FUNCTION__ << ": Complete" << std::endl;
      };

      virtual const VisitCounterSimple<T>::ImageType* GetImage() const override {
	throw std::runtime_error("Not implemented");
      }
      
    private:
      const int nDims = 3;
      const int nVertices = 4;
    };
  }
}
