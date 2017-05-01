using UnityEngine;
using System.Collections;

public class EnemyMovement : MonoBehaviour {

	public float movementSpeed = 2;
	public float timeToMove;
	// Use this for initialization
	void Start () 
	{
	
	}
	
	// Update is called once per frame
	void Update () 
	{
		timeToMove = Random.Range (0, 50);

		if (timeToMove == 1) {
			transform.Translate (transform.up * (10 * movementSpeed * Time.deltaTime), Space.World);
		} 


		if (timeToMove == 2) 
		{
			transform.Translate (transform.right * (10 * movementSpeed * Time.deltaTime), Space.World);
		}

		if (timeToMove == 3) {
			transform.Translate (transform.up * (-10 * movementSpeed * Time.deltaTime), Space.World);
		} 


		if (timeToMove == 4) 
		{
			transform.Translate (transform.right * (-10 * movementSpeed * Time.deltaTime), Space.World);
		}
	

	
	}
}
