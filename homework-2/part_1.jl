using LinearAlgebra
using Plots

struct ExplicitMidpoint{T}
    u_tmp::T
    ExplicitMidpoint(u) = new{typeof(u)}(similar(u)) 
end

struct ForwardEuler end

function solve(method::ForwardEuler,u0,rhs!,tspan,dt,parameters;num_saved_steps=1)
    tf = tspan[2]-tspan[1] # the timespan we have
    Nsteps = ceil(Int, tf/dt) # calculate the number of steps
    dt = tf/Nsteps
    u = copy(u0)
    t = tspan[1]
    du = zeros(size(u0))

    otput = zeros(size(u0)[1], size(u0)[2], num_saved_steps+1)
    otput[:,:,1] = u0 # the first of the output is the initial positions
    page = 1
    numeval = 0

    freq = floor(Int, Nsteps/num_saved_steps) # for every freq iteration, we store the positions of the particles

    for i = 1:Nsteps
            ttmp = (i-1) * dt + t
            rhs!(du, u, ttmp, parameters)
            numeval = numeval + 1 # one more evaluation of rhs!
            @. u = u + dt * du
        if i % freq == 0
            page = page+1 # store the solution snapshots in this case
            otput[:,:,page] = u
        end
    end

    return otput, numeval
end

function solve(method::ExplicitMidpoint,u0,rhs!,tspan,dt,parameters;num_saved_steps=1)
    tf = tspan[2]-tspan[1]
    Nsteps = ceil(Int, tf/dt)
    dt = tf/Nsteps
    u = copy(u0)
    t = tspan[1]
    du = zeros(size(u0)[1], size(u0)[2])

    otput = zeros(size(u0)[1], size(u0)[2], num_saved_steps+1)
    otput[:,:,1] = u0
    page = 1
    numeval = 0

    freq = floor(Int, Nsteps/num_saved_steps)

    for i = 1:Nsteps
            rhs!(du, u,t,parameters)
            numeval = numeval + 1
        
            utmp = method.u_tmp # initialize the utmp matrix
            utmp = u + 0.5.*du.*dt # find the midpoint first

            rhs!(du, utmp,t+0.5*dt,parameters)
            numeval = numeval + 1
            u = u + dt * du
            t = t + dt

        if i % freq == 0
            page = page+1
            otput[:,:,page] = u
        end
    end

    return otput, numeval
end

