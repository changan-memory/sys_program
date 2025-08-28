while :; do ps axj | head -1 ; echo "-------"; ps ajx | grep proc | grep -v grep | grep -v .vscode; sleep 1; done

