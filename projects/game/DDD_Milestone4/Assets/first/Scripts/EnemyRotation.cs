using UnityEngine;
using System.Collections;

public class EnemyRotation : MonoBehaviour {

	public int rotationOffset = 0;
	//Player.PlayerStats player = new Player.PlayerStats ();
	public float xVal;
	public float yVal;
	GameObject p1;
	// Use this for initialization
	void Start () {
		p1 = GameObject.Find ("Player");

	}

	// Update is called once per frame
	void Update () 
	{
		xVal = p1.transform.position.x;
		yVal = p1.transform.position.y;
		Vector3 playerPosition = new Vector3 (xVal, yVal);
		Vector3 difference = playerPosition - transform.position;
		//difference.Normalize ();

		float rotZ = Mathf.Atan2 (difference.y, difference.x) * Mathf.Rad2Deg;
		transform.rotation = Quaternion.Euler (0f, 0f, rotZ + rotationOffset);

	}
}
