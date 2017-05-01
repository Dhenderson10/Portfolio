using UnityEngine;
using System.Collections;
using System.Collections.Generic;

public class BehaviorTree : MonoBehaviour {

	private BTNode mRoot; 
	private bool startedBehavior;

	public BTNode Root { get { return mRoot; } }
	public Dictionary<string, object> Blackboard { get; set; }

	// Use this for initialization
	void Start () {
		Blackboard = new Dictionary<string, object> ();
		Blackboard.Add ("WorldBounds", new Rect (0, 0, 5, 5));

		startedBehavior = false;
	
		mRoot = new BTRepeaterNode(this, new BTSequencerNode(this, 
			new BTNode[] { new BTRandomWalkNode (this) }));
		
	}

	// Update is called once per frame
	void Update () {
		transform.rotation = new Quaternion (0, 0, 0, 0);
		if (!startedBehavior) {
			StartCoroutine (RunBehavior ());
			startedBehavior = true;
		}
	}

	IEnumerator RunBehavior() 
	{ 
		BTNode.Result result = Root.Execute ();
		while (result == BTNode.Result.Running) {
			//Debug.Log ("Root result: " + result);
			yield return null;
			result = Root.Execute ();
		}
		//Debug.Log ("Behavior has finished: " + result);
	}
} 