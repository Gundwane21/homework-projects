from evaluator import *
import math

Datas = get_data()

def new_move():
	global Datas
	global gravity
	global delta_t

    gravity = float(Datas[0])
    delta_t = float(Datas[1])

    changes = []

    for i in range(2, len(Datas)):
		particle1 = Datas[i]

		changes_x = float(particle1[3]) * delta_t
		changes_y = float(particle1[4]) * delta_t

		changes.append([changes_x, changes_y])

		particle1[1] += changes_x
		particle1[2] += changes_y
    for k in range(2, len(Datas)):
		particle1 = Datas[k]

		F = [0, 0]
		for j in range(2, len(Datas)):
			if k == j:
				continue

			particle2 = Datas[j]

            distance = math.sqrt(math.pow(float(particle2[1] - particle1[1]), 2) + math.pow(float(particle2[2] - particle1[2]), 2))
            coeff = float(gravity * particle1[0] * particle2[0]) / math.pow(distance, 3)   #coefficient of the force calculation

            updated_force = [coeff * (float(particle2[1] - particle1[1])), coeff * (float(particle2[2] - particle1[2]))]

			F[0] += updated_force[0]
			F[1] += updated_force[1]

		ac = [float(F[0]/particle1[0]), float(F[1]/particle1[0])] #acceleration of the moving particles

		particle1[3] += float(ac[0] * delta_t)
		particle1[4] += float(ac[1] * delta_t)

	return changes
