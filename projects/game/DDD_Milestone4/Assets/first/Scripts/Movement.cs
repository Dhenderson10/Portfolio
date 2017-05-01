using UnityEngine;
using System.Collections;

public class Movement : MonoBehaviour {
	public float verticalInput;
	public float horizontalInput;
	public bool jump;
	public Vector3 mousePosition;
	public float turnSpeed = 130;
	public float movementSpeed = 4;
	public Animation anime;
	public Animator anichan;
	// Use this for initialization
	void Start () {
		//anime = GetComponent<Animator> ();;
	}

	// Update is called once per frame
	void Update () {
		transform.rotation = new Quaternion (0, 0, 0, 0);
		movementSpeed = 4;
		verticalInput = Input.GetAxis ("Vertical");
		horizontalInput = Input.GetAxis ("Horizontal");
		//jump = Input.GetButton ("Jump");

		//move spirte up/down

		transform.Translate (transform.up * (verticalInput * movementSpeed * Time.deltaTime), Space.World);
		transform.Translate (transform.right * (horizontalInput * movementSpeed * Time.deltaTime), Space.World);

		if (verticalInput != 0 || horizontalInput != 0) {
			//anime.Play ();

			anichan.StopPlayback();


		} else 
		{
			anichan.StartPlayback();
		
		}
		//move sprite forward/back
		//transform.RotateAround (transform.right * (horizontalInput * movementSpeed * Time.deltaTime), Space.World);
		//transform.Rotate(Vector3.back, turnSpeed * Time.deltaTime * horizontalInput);
		//camera
		//transform.Translate (transform.forward * (


		//transform.LookAt(transform.position);

		mousePosition = Input.mousePosition;

	}

	void onCollisionEnter (Collision col)
	{
		movementSpeed = 0;

	}

}

