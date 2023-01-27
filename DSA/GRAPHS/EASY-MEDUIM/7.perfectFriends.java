import java.io.*;
import java.util.*;

public class Main {
    static class Edge {
        int src;
        int nbr;
  
        Edge(int src, int nbr) {
           this.src = src;
           this.nbr = nbr;
        }
     }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        int k = Integer.parseInt(br.readLine());
  
        int vtces = n;
        ArrayList<Edge>[] graph = new ArrayList[vtces];
        for (int i = 0; i < vtces; i++) {
           graph[i] = new ArrayList<>();
        }
  
        int edges = k;
        for (int i = 0; i < edges; i++) {
           String[] parts = br.readLine().split(" ");
           int v1 = Integer.parseInt(parts[0]);
           int v2 = Integer.parseInt(parts[1]);
           graph[v1].add(new Edge(v1, v2));
           graph[v2].add(new Edge(v2, v1));
        }



        // write your code here
        ArrayList<ArrayList<Integer>> comps = new ArrayList<>();
        boolean visited [] = new boolean[vtces];

        for (int i = 0 ; i < vtces ; i++) {
            if (visited[i] == false) {
                ArrayList<Integer> comp = new ArrayList<>();
                getComps(graph, visited,i, comp);
                comps.add(comp);
            }
        }
        // System.out.println(comps);
        int ans = 0;
        for (int i = 0; i < comps.size(); i++)
        {
            // int prev = comps[i].size(); // this will give some error
            int prev = comps.get(i).size();
            for (int j = i + 1; j < comps.size(); j++) {
                // int next = comps[j].size(); // this will give some error
                int next = comps.get(j).size();
                ans += prev * next;
                
            }
        }

        System.out.println(ans);
    }


    // printing all the vertices connected with the source
    static void getComps(ArrayList<Edge>[] graph, boolean [] visited, int src, ArrayList<Integer> comp) 
    {
        visited[src] = true;
        comp.add(src);

        for (Edge e : graph[src])
        {
            if (visited[e.nbr] == false)
            {
                getComps(graph,visited, e.nbr, comp);
            }
        }
    }
}
