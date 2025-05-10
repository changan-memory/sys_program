while :; do ps axj | head -1 ; ps ajx | grep proc | grep -v grep; sleep 1; done

