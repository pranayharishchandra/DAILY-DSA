import java.io.*;
import java.util.*;

public class Main {
    static class Edge {
        int src;
        int nbr;
        int wt;

        Edge(int src, int nbr, int wt) {
            this.src = src;
            this.nbr = nbr;
            this.wt = wt;
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int vtces = Integer.parseInt(br.readLine());
        ArrayList<Edge>[] graph = new ArrayList[vtces];
        for (int i = 0; i < vtces; i++) {
            graph[i] = new ArrayList<>();
        }

        int edges = Integer.parseInt(br.readLine());
        for (int i = 0; i < edges; i++) {
            String[] parts = br.readLine().split(" ");
            int v1 = Integer.parseInt(parts[0]);
            int v2 = Integer.parseInt(parts[1]);
            int wt = Integer.parseInt(parts[2]);
            // undirected graph
            graph[v1].add(new Edge(v1, v2, wt));
            graph[v2].add(new Edge(v2, v1, wt));
        }

        // write your code here
        ArrayList<ArrayList<Integer>> comps = new ArrayList<>();
        boolean visited[] = new boolean[vtces];

        for (int i = 0; i < vtces; i++) {
            if (visited[i] == false) {
                ArrayList<Integer> comp = new ArrayList<>();
                getComps(graph, visited, i, comp);
                comps.add(comp);
            }
        }

        if (comps.size() == 1)
            System.out.println("true");
        else
            System.out.println("false");
    }

    // printing all the vertices connected with the source
    static void getComps(ArrayList<Edge>[] graph, boolean[] visited, int src, ArrayList<Integer> comp) {
        visited[src] = true;
        comp.add(src);

        for (Edge e : graph[src]) {
            if (visited[e.nbr] == false) {
                getComps(graph, visited, e.nbr, comp);
            }
        }
    }
}
