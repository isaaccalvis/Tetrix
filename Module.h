#ifndef __MODULE_H__
#define __MODULE_H__

class Module {
private:
	bool enabled = true;
public:
	virtual ~Module() {}

	virtual bool Init() { return true; }
	virtual bool Update() { return true; }
	virtual bool PostUpdate() { return true; }
	virtual bool Finish() { return true; }

	bool IsEnabled() const { return enabled; }

	void Enable() {
		if (enabled == false) {
			enabled = true;
			Init();
		}
	}

	void Disable() {
		if (enabled == true) {
			enabled = false;
			Finish();
		}
	}
};

#endif