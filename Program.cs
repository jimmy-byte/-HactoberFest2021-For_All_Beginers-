using DocumentFormat.OpenXml.Bibliography;
using System;
using System.Collections;

namespace TSP_ConsoleApp1
{
    //This is the class that implements the greedy solution for TSP
    class GreedyRoute
    {
        public GreedyRoute(City[] list)
        {
            Cities = list;
            visited = new bool[Cities.Length];
            for(int i = 0; i < visited.Length; i++)
                visited[i] = false;
            r = new Random();
            startIndex = r.Next() % Cities.Length;
            numVisited = 1;
            route = new ArrayList();
        }
        public void SetRoute()
        {
            if(startIndex >= Cities.Length)
                startIndex = startIndex % Cities.Length;
            //start with a random city
            City currentCity = Cities[startIndex];
            route.Add(Cities[startIndex]);
            visited[startIndex] = true;
            City nextDest = null;
            while (numVisited < Cities.Length)
            {
                double minCost = Double.PositiveInfinity;
                int currentIndex = -1;
                //look for the city that has the lowest cost to get to
                for(int i = 0; i < Cities.Length; i++)
                {
                    if(!visited[i])
                    {
                        double tempCost = currentCity.costToGetTo(Cities[i]);
                        if (tempCost < minCost)
                        {
                            minCost = tempCost;
                            nextDest = Cities[i];
                            currentIndex = i;
                        }
                    }
                }
                //break if a dead-end city is reached
                if (minCost == Double.PositiveInfinity)
                    break;
                else
                {
                    route.Add(nextDest);
                    visited[currentIndex] = true;
                    currentCity = nextDest;
                }
            }
            //set the route to null if not completed
            if (currentCity.costToGetTo(Cities[startIndex]) == Double.PositiveInfinity)
                route = null;
            else if (route.Count < Cities.Length)
                route = null;
        }
        public ArrayList GetRoute()
        {
            return route;
        }
        //get ready to form a new route
        public void Reset()
        {
            startIndex = r.Next();
            route = new ArrayList();
        }
        private Random r;
        private City[] Cities;
        private bool[] visited;
        private int startIndex;
        private int numVisited;
        private ArrayList route;
    }
}
