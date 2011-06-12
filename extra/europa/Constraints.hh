/*********************************************************************
 * Software License Agreement (BSD License)
 * 
 *  Copyright (c) 2011, MBARI.
 *  All rights reserved.
 * 
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 * 
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above
 *     copyright notice, this list of conditions and the following
 *     disclaimer in the documentation and/or other materials provided
 *     with the distribution.
 *   * Neither the name of the TREX Project nor the names of its
 *     contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
 * 
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 *  FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 *  COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 *  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 *  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 *  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 *  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 *  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 *  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *  POSSIBILITY OF SUCH DAMAGE.
 */
#ifndef H_Constraints
# define H_Constraints

# include "ReactorPropagator.hh"

# include <PLASMA/Constraint.hh>

namespace TREX {
  namespace europa {

    namespace details {
      EUROPA::TokenId parent_token(EUROPA::ConstrainedVariableId const &var);
    }

    class ReactorConstraint :public EUROPA::Constraint {
    public:
      ReactorConstraint(EUROPA::LabelStr const &name, 
			EUROPA::LabelStr const &propagatorName,
			EUROPA::ConstraintEngineId const &cstrEngine,
			std::vector<EUROPA::ConstrainedVariableId> const &variables);
      virtual ~ReactorConstraint() {}
      
    protected:
      Assembly &assembly();
      
    private:
      Assembly *m_assembly;
    };

    
    class CheckExternal :public ReactorConstraint {
    public:
      CheckExternal(EUROPA::LabelStr const &name, 
		    EUROPA::LabelStr const &propagatorName,
		    EUROPA::ConstraintEngineId const &cstrEngine,
		    std::vector<EUROPA::ConstrainedVariableId> const &variables);
      void handleExecute();
    private:
      EUROPA::Domain *m_test;
      EUROPA::Domain *m_obj;
    };


    class CheckInternal :public ReactorConstraint {
    public:
      CheckInternal(EUROPA::LabelStr const &name, 
		    EUROPA::LabelStr const &propagatorName,
		    EUROPA::ConstraintEngineId const &cstrEngine,
		    std::vector<EUROPA::ConstrainedVariableId> const &variables);
      void handleExecute();
    private:
      EUROPA::Domain *m_test;
      EUROPA::Domain *m_obj;
    };

    class Bind :public EUROPA::Constraint {
    public:
      Bind(EUROPA::LabelStr const &name, 
	   EUROPA::LabelStr const &propagatorName,
	   EUROPA::ConstraintEngineId const &cstrEngine,
	   std::vector<EUROPA::ConstrainedVariableId> const &variables);
      bool guardSatisfied() const;
      void handleExecute();
    private:
      EUROPA::Domain *m_target;
      EUROPA::Domain *m_default;
    }; // Bind

  }
}

#endif // H_Constraints
