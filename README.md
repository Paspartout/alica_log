# Alica Log

This small utility logs [alica](https://github.com/carpe-noctem-cassel/alica) states in the following format:

```
(07.02.2018 17:57:13.512) [9] Received first Info
(07.02.2018 17:57:13.579) [11] Received first Info
(07.02.2018 17:57:15.513) [9] State: AlignExec -> GrabBall
(07.02.2018 17:57:18.179) [9] State: GrabBall -> Wait
(07.02.2018 17:57:22.513) [11] Plan: CornerKick -> DefendPlay
(07.02.2018 17:57:22.513) [11] State: AlignRecv -> Block
(07.02.2018 17:57:22.513) [11] Task: ReceiveStandard -> Block
(07.02.2018 17:57:22.580) [9] Plan: CornerKick -> StandardAttack
(07.02.2018 17:57:22.580) [9] State: Wait -> GetBall
(07.02.2018 17:57:22.580) [9] Task: ExecuteStandard -> Attack
(07.02.2018 17:57:23.515) [9] Plan: StandardAttack -> Dribble
(07.02.2018 17:57:23.515) [9] State: GetBall -> Dribble
(07.02.2018 17:57:23.580) [11] Plan: DefendPlay -> AttackPlay
(07.02.2018 17:57:23.580) [11] State: Block -> Release
(07.02.2018 17:57:23.580) [11] Task: Block -> ReceivePassInGame
(07.02.2018 17:57:23.913) [9] Plan: Dribble -> StandardAttack
(07.02.2018 17:57:23.913) [9] State: Dribble -> GetBall
(07.02.2018 17:57:24.181) [9] Plan: StandardAttack -> Dribble
(07.02.2018 17:57:24.181) [9] State: GetBall -> Dribble
(07.02.2018 17:57:24.580) [9] Plan: Dribble -> PassPlay
(07.02.2018 17:57:24.580) [9] State: Dribble -> Pass
(07.02.2018 17:57:24.580) [9] Task: Attack -> DefaultTask
(07.02.2018 17:57:24.847) [9] Plan: PassPlay -> Dribble
(07.02.2018 17:57:24.847) [9] State: Pass -> Dribble
(07.02.2018 17:57:24.847) [9] Task: DefaultTask -> Attack
(07.02.2018 17:57:25.114) [9] Plan: Dribble -> StandardAttack
(07.02.2018 17:57:25.114) [9] State: Dribble -> GetBall
(07.02.2018 17:57:25.248) [9] Plan: StandardAttack -> Dribble
(07.02.2018 17:57:25.248) [9] State: GetBall -> Dribble
(07.02.2018 17:57:25.380) [9] Plan: Dribble -> StandardAttack
(07.02.2018 17:57:25.380) [9] State: Dribble -> GetBall
(07.02.2018 17:57:25.514) [9] Plan: StandardAttack -> Dribble
(07.02.2018 17:57:25.514) [9] State: GetBall -> Dribble
(07.02.2018 17:57:25.647) [9] Plan: Dribble -> StandardAttack
(07.02.2018 17:57:25.647) [9] State: Dribble -> GetBall
(07.02.2018 17:57:25.914) [9] Plan: StandardAttack -> Dribble
(07.02.2018 17:57:25.915) [9] State: GetBall -> Dribble
(07.02.2018 17:57:26.047) [9] Plan: Dribble -> StandardAttack
(07.02.2018 17:57:26.047) [9] State: Dribble -> GetBall
(07.02.2018 17:57:26.315) [9] Plan: StandardAttack -> Dribble
(07.02.2018 17:57:26.315) [9] State: GetBall -> Dribble
(07.02.2018 17:57:26.446) [9] Plan: Dribble -> WM16
(07.02.2018 17:57:26.446) [9] State: Dribble -> Stop
(07.02.2018 17:57:26.446) [9] Task: Attack -> DefaultTask
(07.02.2018 17:57:26.512) [11] Plan: AttackPlay -> WM16
(07.02.2018 17:57:26.512) [11] State: Release -> Stop
(07.02.2018 17:57:26.512) [11] Task: ReceivePassInGame -> DefaultTask
```



