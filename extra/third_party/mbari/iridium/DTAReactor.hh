#ifndef H_mbari_DTAReactor
# define H_mbari_DTAReactor

# include "SbdMailer.hh"
# include <trex/transaction/TeleoReactor.hh>

namespace mbari {
  namespace iridium {

    class DTAReactor :public TREX::transaction::TeleoReactor {
    public:
      DTAReactor(TREX::transaction::TeleoReactor::xml_arg_type arg);
      ~DTAReactor();

    private:
      bool synchronize();
      void handleRequest(TREX::transaction::goal_id const &g);
      void notify(TREX::transaction::Observation const &obs);

      bool m_active;
      TREX::utils::Symbol m_drifter;
      TREX::utils::Symbol m_path;
      double              m_factor;
      bool                m_lagrangian;
      
      std::pair<double, double> m_pos, m_speed;
      bool m_have_pos, m_have_speed;
      bool m_waiting, m_use_iridium;

      enum vehicle_mode {
	UNKNOWN =0,
	WAITING,
	GOAL_SENT,
	RUNNING
      };

      vehicle_mode m_trex_state;
      
      
      std::string    m_imei;
      SbdMailer      m_iridium;
    };

  }
}

#endif // H_mbari_DTAReactor 