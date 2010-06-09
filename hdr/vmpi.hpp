#ifndef VMPI_H_
#define VMPI_H_
//==========================================================
// Includes
//==========================================================
#include "create.hpp"
#include <string>
#include <vector>

#ifdef MPICF
	#include <mpi.h>
#endif

using std::string;
//using std::vector;

namespace vmpi{
	
	extern int my_rank; 					///< Local CPU ID
	extern int num_processors;			///< Total number of CPUs
	extern int mpi_mode; 				///< MPI Simulation Mode (0 = Mirrored, 1 = Statistical Parallelism, 2 = Geometric Decomposition, 3 = granular decomposition)
	extern int num_core_atoms;			///< Number of atoms on local CPU with no external communication
	extern int num_bdry_atoms;			///< Number of atoms on local CPU with external communication
	extern int num_halo_atoms;			///< Number of atoms on remote CPUs needed for boundary atom integration
	
	extern char hostname[20];			///< Hostname of local CPU
	extern double start_time;			///< Simulation start time on local CPU
	extern double end_time;				///< Simulation end time on local CPU
	extern double min_dimensions[3]; 	///< Minimum coordinates of system on local cpu
	extern double max_dimensions[3]; 	///< Maximum coordinates of system on local cpu
	
	extern std::vector<int> send_atom_translation_array;
	extern std::vector<int> send_start_index_array;
	extern std::vector<int> send_num_array;
	extern std::vector<double> send_spin_data_array;

	extern std::vector<int> recv_atom_translation_array;
	extern std::vector<int> recv_start_index_array;
	extern std::vector<int> recv_num_array;
	extern std::vector<double> recv_spin_data_array;
	
	#ifdef MPICF
		extern std::vector<MPI::Request> requests;
		extern std::vector<MPI::Status> stati;
	#endif

	//functions declarations
	extern int geometric_decomposition(int, double []);
	extern int crystal_xyz(std::vector<cs::catom_t> &);
	extern int copy_halo_atoms(std::vector<cs::catom_t> &);
	extern int identify_boundary_atoms(std::vector<cs::catom_t> &, std::vector<std::vector <int> > &);
	extern int init_mpi_comms(std::vector<cs::catom_t> & catom_array);
}

//==========================================================
// Namespace mpi_generic
//==========================================================
/*namespace mpi_generic{
	extern int mpi_mode;
	extern int my_rank;
	extern int num_processors;
	extern char hostname[20];
	extern double start_time;
	extern double end_time;
}
//==========================================================
// Namespace mpi_create_variables
//==========================================================
namespace mpi_create_variables{
	extern int int_mpi_offset[3];
	extern int int_mpi_halo_min[3];
	extern int int_mpi_halo_max[3];
	extern int int_mpi_core_min[3];
	extern int int_mpi_core_max[3];
	extern int mpi_interaction_range;
	extern double mpi_offset[3];
	extern double mpi_full_system_dimensions[3];
	extern double mpi_system_min[3];	
	extern double mpi_system_max[3];
	extern std::string decomposition_type;
	// Defines local(0), boundary(1), halo(2) atoms
	extern valarray<int> mpi_atom_comm_class_array;
	extern valarray<int> mpi_atom_location_array;
	extern valarray<int> mpi_atom_global_coord_array;
	extern valarray<int> mpi_global_atom_number_array;
	//extern valarray<int> mpi_global_atom_location_array;

	extern bool mpi_comms_identify;
}
//==========================================================
// Namespace mpi_stats
//==========================================================
namespace mpi_stats{
}
//==========================================================
// Namespace mpi_comms
//==========================================================
namespace mpi_comms{

	extern int num_core_atoms;
	extern int num_boundary_atoms;
	extern int num_halo_atoms;

	extern int num_boundary_swaps;
	extern int num_halo_swaps;

	extern int num_messages;
	
	#ifdef MPICF
		extern valarray<MPI::Request> requests;
		extern valarray<MPI::Status> stati;
	#endif

	extern valarray<int> send_atom_translation_array;
	extern valarray<int> send_start_index_array;
	extern valarray<int> send_num_array;
	extern valarray<double> send_spin_data_array;

	extern valarray<int> recv_atom_translation_array;
	extern valarray<int> recv_start_index_array;
	extern valarray<int> recv_num_array;
	extern valarray<double> recv_spin_data_array;
}
*/

#endif /*VMPI_H_*/
