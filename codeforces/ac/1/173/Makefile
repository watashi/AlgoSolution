profile: E.hs
	ghc -O --make E.hs -prof -auto-all -caf-all -fforce-recomp
	time ./E +RTS -pa < E.in > /dev/null
run: E.hs
	ghc -O --make E.hs -fforce-recomp
	time ./E < E.in > /dev/null
