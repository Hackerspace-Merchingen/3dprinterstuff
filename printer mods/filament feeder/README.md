# Filament feeder cascade
a different approach to the extruder problem

An extruder has to work against 2 forces simultaneously: It has to press the filament through the nozzle and it has to unwind the filament from the roll. At the same time, it must also be able to maintain a precisely consistent speed.

The usual approach is to support the filament roll in such a way that it exerts as little force as possible to unwind it. Since the roll varies in fullness as it is unrolled, this is a difficult task.

It would be much better if the extruder had only one task. It is hard enough to make the force for the extrusion process itself consistent.

So here's a new approach to the problem: We add another motor, which also has only one task: To unwind the filament from the roll and provide it in such a way that the actual extruder can access the filament without force.

## Prototype build

![IMG_20210514_144850](https://user-images.githubusercontent.com/3326711/118272950-a1234e00-b4c3-11eb-8c8a-8284dd5ae31d.jpg?v=1&s=100)
