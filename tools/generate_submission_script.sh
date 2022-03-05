# compulsory inputs: nodes, ppn, job_name, np, prog_name
# optional inputs: ${prog_args}

echo "#PBS -l walltime=00:01:00,nodes=${nodes}:ppn=${ppn}
#PBS -N ${job_name}
#PBS -q batch

# echo 'workdir: ' \${PBS_O_WORKDIR}
# echo 'nodefile:' \${PBS_NODEFILE}
cd \${PBS_O_WORKDIR}
mpirun --hostfile \${PBS_NODEFILE} -np ${np} '${prog_name}' ${prog_args}"
