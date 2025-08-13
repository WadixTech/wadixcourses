# Trust-Zone Example: Secure --> Non-Secure --> Secure

Examples        | Functionality to Test
----------------|-------------------------------------------------------------------------------------------------------------------
example_01_s.c  | secure --> non-secure: BLXNS to non-secure function
			    | non-secure --> secure: BX to FNC_RETURN return value previously updated in LR register upon execution of BLXNS
				| Without SAU configuration of target memory to be non-secure --> secure fault will be triggered
----------------|--------------------------------------------------------------------------------------------------------------------				
example_02_s.c  | Use SAU to configure target memory to be non-secure
                | Use proper configuration to switch back and forth from secure to non-secure then back to secure