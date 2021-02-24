def solve (N, edge):
    # Type your code here

    # comb_of_paths = {}
    # for data in edge:
    #     comb_of_paths[data[0]] = data[1]
    #     if data[0] in comb_of_paths:
    #         comb_of_paths[data[0]].append(data[1])

    res_node = []
    res_node_map = {}
    node_one = []
    key_dic = list( map( lambda x: x[0], edge))
    key_val = list( map( lambda x: x[1], edge))
    for val in key_dic:
        node_one.append(val)

    for val in key_val:
        node_one.append(val)

    nodes = list(set(node_one))
    
    for n in nodes:
        path_length_of_nodes = 0
        flag = True
        initial_node = n
        while(flag):
            for idx, edges in enumerate(edge):
              if n == edges[0]:
                val = edge[idx][1]
                path_length_of_nodes +=1
                n = val

            else:
              flag = False

            res_node.append(path_length_of_nodes)
            res_node_map[initial_node] = path_length_of_nodes

    max_path = max(res_node)
    nodes_return = []
    for key, value in res_node_map.items():
        if res_node_map[key] == max_path:
            nodes_return.append(key)


    for idx, val in enumerate(nodes):
        if val in nodes_return:
            nodes[idx] = 1

        else:
            nodes[idx] = 0


    return nodes# Dummy return

N = int(input())
edge = [list(map(int, input().split())) for i in range(N-1)]

out_ = solve(N, edge)
print (' '.join(map(str, out_)))