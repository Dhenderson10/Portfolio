using UnityEngine;
using System.Collections;
using System.Collections.Generic;
using UnityEngine.SceneManagement;


public class LevelLoader : MonoBehaviour {

	public Transform obstaclePrefab;
	//LOGIC
	//Instantiate an object at the start of the level
	//first randomize a map within a reasonable scale
	//then ur gonna have to put blockers that fit that size
	//create random x, y  variables that are then modded to the length and with of the map
	//have a random number of times an object is instanted modded by the level
	//have a while loop that executes by this # ^


	//public float enemyXVal; //enemies x position 
	//public float enemyYVal; //enemies y position
	//public float mapXBounds; 
	//public float mapYBounds;
	public Transform tilePrefab;
	public Vector2 mapSize;

	List<Coord> allTileCoords;
	Queue<Coord> shuffledTileCoords;


	public GameObject[] enemyArray = new GameObject[1];
	int obstacleCount;
	public Vector3[] occupiedPositions;
	int enemyCount;
	bool enemiesAlreadyGenerated = false;
	public int seed;
	public GameObject enemyPrefabZero;
	public GameObject enemyPrefabOne;
	public GameObject skellyPrefab;
	public GameObject witchPrefab;

	public GameObject UI;
	//public int maxObstacleCount;
	//public int minObstacleCount;
	public int maxEnemyCount;
	public int minEnemyCount;
	public int enemySelector = 0;
	public int level;
	public int enemyArrayMax = 2;
	public Transform crowdPrefab;

	//public GameObject[] enemyArray = new GameObject[2]

	public void GenerateMap ()
	{
		allTileCoords = new List<Coord> ();

		for (int x = 0; x < mapSize.x; x++) 
		{
			for (int y = 0; y < mapSize.y; y++) 
			{
				allTileCoords.Add (new Coord (x, y));

			}

		}

		shuffledTileCoords = new Queue<Coord>(Utility.ShuffleArrary(allTileCoords.ToArray(), seed));



		for (int x = 0; x < mapSize.x; x++) 
		{
			for (int y = 0; y < mapSize.y; y++) 
			{
				Vector3 tilePosition = CoordToPosition (x, y);
				//this is affecting x and z variables and may need to be changed
				if (level > 9)
				{
					tilePrefab.GetComponent<SpriteRenderer> ().color = Random.ColorHSV();
					while (tilePrefab.GetComponent<SpriteRenderer> ().color == Color.black) {
						tilePrefab.GetComponent<SpriteRenderer> ().color = Random.ColorHSV();

					}
				}
				Transform newTile = Instantiate(tilePrefab, tilePosition, Quaternion.Euler(Vector3.right)) as Transform;

			}
		}

		for (int x = -10; x < mapSize.x + 10; x++) 
		{
			for (int y = -10; y < mapSize.y + 10; y++) 
			{
				Vector3 crowdPosition = CoordToPosition (x, y);
				//this is affecting x and z variables and may need to be changed
				Transform newCrowd = Instantiate(crowdPrefab, crowdPosition, Quaternion.Euler(Vector3.right)) as Transform;

			}
		}

		if (level <= 9) 
		{
			for (int i = 0; i < obstacleCount; i++) 
			{
				Coord randomCoord = GetRandomCoord ();
				Vector3 obstaclePosition = CoordToPosition (randomCoord.x, randomCoord.y);
				occupiedPositions [i] = obstaclePosition;
				Transform newObstacle = Instantiate (obstaclePrefab, obstaclePosition, Quaternion.identity) as Transform;
			}
		}

		if(enemiesAlreadyGenerated == false)
		{
			bool samePosition = false;

			//Debug.Log (randomEnemy);
			for (int i = 0; i < enemyCount; i++) 
			{
				int randomEnemy = Random.Range (0, enemyArrayMax);
				Debug.Log ("random int: " + randomEnemy);//THIS CONTROLS THE ARRY ENEMY, NEED VARIABLE
				//Debug.Log (randomEnemy);
				Coord randomCoord = GetRandomCoord ();
				Vector3 enemyPosition = CoordToPosition (randomCoord.x, randomCoord.y);
				while (samePosition == false)
				{
					for (int y = 0; y < obstacleCount; y++)
					{
						if (enemyPosition == occupiedPositions [y]) 
						{
							enemyPosition = CoordToPosition (randomCoord.x, randomCoord.y);
							y = 0;
						}

					}
					samePosition = true;
				}
			samePosition = false;
				GameObject newEnemy = Instantiate (enemyArray[randomEnemy], enemyPosition, Quaternion.identity) as GameObject;
			}
		
		}
		enemiesAlreadyGenerated = true;

	}

	Vector3 CoordToPosition(int x, int y)
	{
		return new Vector3 (-mapSize.x / 2 + 0.5f + x, -mapSize.y / 2 + 0.5f + y, 0);
	}

	// Use this for initialization
	Utility tool = new Utility();


		
	
	void Start () {
		Instantiate (UI);
		level = PlayerPrefs.GetInt ("level");
		if (level > 9) 
		{
			mapSize.x = Random.Range (20, 30);
			mapSize.y = Random.Range (20, 30);
		}
		mapSize.x = Random.Range (9, 25);
		mapSize.y = Random.Range (9, 25);
		seed = Random.Range (1, 99);
		difficultyEscalator (level); //should get int for this...level
		obstacleCount = Random.Range (4, 10);
		enemyCount = Random.Range(minEnemyCount, maxEnemyCount);
		occupiedPositions = new Vector3[obstacleCount];
		enemiesAlreadyGenerated = false;
		enemyArray = new GameObject[3];
		initalizeEnemyArray (level); //should be dependent on int level variable
 		GenerateMap (); //passsing in number for how many numbers to generate for random enemy array
	}

	// Update is called once per frame
	void Update () {
		LevelOver ();
		if (Input.GetKeyDown (KeyCode.Escape) == true) {
			SceneManager.LoadScene (5);
		}
		if (PlayerPrefs.GetInt ("health") == 0) {
			SceneManager.LoadScene (6);
		}
	}

	public void difficultyEscalator(int level)
	{
		if (level <= 3) 
		{
			tilePrefab.GetComponent<SpriteRenderer> ().color = Color.gray;
			maxEnemyCount = 6 + level;
			minEnemyCount = 2 + (level / 2);
			enemySelector = 0;
			enemyArrayMax = 2;
		}
		if (level <= 6 && level > 3) 
		{
			tilePrefab.GetComponent<SpriteRenderer> ().color = Color.red;
			maxEnemyCount = 9 + level;
			minEnemyCount = 4 + (level / 2);
			enemySelector = 1;
			enemyArrayMax = 3;

		}
		if (level <= 9 && level > 6) 
		{
			tilePrefab.GetComponent<SpriteRenderer> ().color = Color.yellow;
			maxEnemyCount = 9 + level;
			minEnemyCount = 4 + (level / 2);
			enemySelector = 1;
			enemyArrayMax = 4;

		}
		if (level > 9) {
			
			maxEnemyCount = 10 + ((level - 5) / 2);
			enemyArrayMax = 4;
		}


	}

	public void initalizeEnemyArray(int level)
	{
		if (level <= 3) 
		{
			enemyArray = new GameObject[2];
			enemyArray[0] = enemyPrefabZero;
			enemyArray[1] = enemyPrefabOne;
		}
		if (level <= 6 && level > 3) 
		{
			enemyArray = new GameObject[3];
			enemyArray [0] = enemyPrefabZero;
			enemyArray [1] = enemyPrefabOne;
			enemyArray [2] = skellyPrefab;
		}
		if (level <= 9 && level > 6) 
		{
			enemyArray = new GameObject[4];
			enemyArray [0] = enemyPrefabZero;
			enemyArray [1] = enemyPrefabOne;
			enemyArray [2] = skellyPrefab;
			enemyArray [3] = witchPrefab;

		}
		if (level > 9) 
		{
			enemyArray = new GameObject[4];
			enemyArray [0] = enemyPrefabZero;
			enemyArray [1] = enemyPrefabOne;
			enemyArray [2] = skellyPrefab;
			enemyArray [3] = witchPrefab;

		}


	}

	public void clearMap()
	{
		//Destroy (enemyPrefab);
		Destroy (tilePrefab);
		Destroy (obstaclePrefab);

	}
		
	public Coord GetRandomCoord()
	{
		Coord randomCoord = shuffledTileCoords.Dequeue ();
		shuffledTileCoords.Enqueue (randomCoord);
		return randomCoord;
	}

	public void LevelOver()
	{
		if (GameObject.FindWithTag ("Enemy") == null || Input.GetKeyDown(KeyCode.C) == true) 
		{
			//play animation?
			PlayerPrefs.SetInt ("health", 10);
			PlayerPrefs.SetInt ("level", level + 1);
			SceneManager.LoadScene (2);

			Debug.Log ("Level: " + level);
		}


	}

	public struct Coord
	{
		public int x;
		public int y;
	

		public Coord(int _x, int _y)
		{
			x = _x;
			y = _y;

		}
	}
}	
