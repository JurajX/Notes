model = mujoco_py.load_model_from_path(path)   # loads model from path; returns PyMjModel
model = mujoco_py.load_model_from_xml(path)    # loads model from string; returns PyMjModel

sim = mujoco_py.MjSim(     # creates a running simulation including its state; wraps PyMjModel and PyMjData
    model,                 # the PyMjModel to simulate
    data=None,             # the PyMjData container for the simulation state; will be created if None
    nsubsteps=1,           # num of MuJoCo steps to run for every call to step(); buffers will be swapped only once per step
    udd_callback=None)     # callback for user-defined dynamics; fn(MjSim) -> dict

sim.get_state()                            # returns a copy of the simulator state
sim.render()                               # renders view from a camera and returns image as an numpy.ndarray
sim.reset()                                # resets the simulation data and clears buffers
sim.save(file, format, keep_inertials)     # saves the simulator model and state to a file with format (‘xml’ or ‘mjb’)
sim.step()                                 # advances the simulation

mujoco_py.MjSimState   # represents a snapshot of the simulator’s state; incl. time, qpos, qvel, act, and udd_state

mujoco_py.PyMjData     # holds all date representing the state of the simulator

mujoco_py.MjSimPool                    # keeps a pool of multiple MjSims and enables stepping them quickly in parallel
MjSimPool.create_from_sim(sim, nsims)  # create an MjSimPool by cloning the provided sim a total of nsims times
MjSimPool.forward(nsims)               # calls mj_forward on all in parallel; if nsims, then only the first nsims simulator are forwarded
MjSimPool.reset(nsims)                 # resets all in pool; if nsims, then only the first nsims simulators are reset
MjSimPool.step(nsubsteps, nsims)       # calls mj_step on all in parallel; if nsims, then only the first nsims simulator are stepped.

mujoco_py.MjViewerBasic(sim)   # simple display GUI showing the scene of an MjSim with a mouse-movable camera
MjViewerBasic.render()         # render the current simulation state to the screen; call the main loop
mujoco_py.MjViewer(sim)        # extends MjViewerBasic to add video recording, interactive time and interaction controls
